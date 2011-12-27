#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>
#include <png.h>

#include <pngio.h>

#ifndef restrict
	#define restrict __restrict__
#endif

#ifndef TRUE
	#define TRUE 1
#endif

#ifndef FALSE
	#define FALSE 0
#endif

/* pngio_meta_t data structure */
struct pngio_meta_t {
	png_structp png;
	png_infop info;
	png_infop end;
};

/* constants */
static const size_t SIZE_SIG = 8;
static const size_t SIZE_SIG_ELEM = 1;

/* prototypes */
static int cmp_sig(FILE *);

static int read_init(struct pngio_meta_t *);
static int read_io_init(struct pngio_meta_t *, const char *, FILE **);
static int read_header(struct pngio_t *, struct pngio_meta_t *);
static int read_image(struct pngio_t *, struct pngio_meta_t *);
static int read_destroy(struct pngio_meta_t *);

static int write_init(struct pngio_meta_t *);
static int write_io_init(struct pngio_meta_t *, const char *, FILE **);
static int write_header(const struct pngio_t *, struct pngio_meta_t *);
static int write_image(const struct pngio_t *, struct pngio_meta_t *);
static int write_destroy(struct pngio_meta_t *);

/* initialization and cleanup */
extern int pngio_init(struct pngio_t * restrict const p)
{
	p->rows = NULL;
	p->image_data = NULL;

	p->bit_depth = -1;
	p->color_type = -1;
	p->width = 0;
	p->height = 0;
	p->rowbytes = -1;

	return 0;
}

extern int pngio_destroy(struct pngio_t * restrict const p)
{
	free(p->rows);
	p->rows = NULL;

	free(p->image_data);
	p->image_data = NULL;

	return 0;
}

extern int pngio_free(struct pngio_t ** restrict const p)
{
	free(*p);
	*p = NULL;

	return 0;
}

/* reading */
extern int pngio_read(struct pngio_t * restrict const p, const char * restrict const filename)
{
	struct pngio_meta_t pm;
	if(read_init(&pm) != 0) {
		read_destroy(&pm);
		return 1;
	}	

	FILE * f = NULL;
	if(read_io_init(&pm, filename, &f) != 0) {
		if(f) fclose(f);
		read_destroy(&pm);
		return 1;
	}

	if(read_header(p, &pm) != 0) {
		if(f) fclose(f);
		read_destroy(&pm);
		return 1;
	}

	if(read_image(p, &pm) != 0) {
		if(f) fclose(f);
		read_destroy(&pm);
		return 1;
	}

	fclose(f);

	if(read_destroy(&pm) != 0) return 1;

	return 0;
}

extern int pngio_write(const struct pngio_t * restrict const p,
		       const char * restrict const filename)
{
	struct pngio_meta_t pm;
	if(write_init(&pm) != 0) {
		write_destroy(&pm);
		return 1;
	}

	FILE * f = NULL;
	if(write_io_init(&pm, filename, &f) != 0) {
		if(f) fclose(f);
		write_destroy(&pm);
		return 1;
	}

	if(write_header(p, &pm) != 0) {
		if(f) fclose(f);
		write_destroy(&pm);
		return 1;
	}

	if(write_image(p, &pm) != 0) {
		if(f) fclose(f);
		write_destroy(&pm);
		return 1;
	}

	fclose(f);

	if(write_destroy(&pm) != 0) return 1;

	return 0;
}

/* facilitative functions */
extern int pngio_is_png(const char * restrict const filename, int * restrict const result)
{
	FILE * f = fopen(filename, "rb");
	if(!(f)) {
		*result = FALSE;
		error(0, errno, "fopen");
		return 1;
	}

	if(cmp_sig(f) != 0) {
		*result = FALSE;
		fclose(f);
		return 1;
	}

	*result = TRUE;

	if(fclose(f) != 0) {
		error(0, errno, "fclose");
		return 1;
	}

	return 0;
}

/* field access */
extern int pngio_image_data(const struct pngio_t * restrict const p,
			    png_byte ** restrict image_data)
{
	if(*image_data) {
		free(*image_data);
		*image_data = NULL;
	}

	/* allocate the image data */
	size_t size = p->rowbytes * p->height * sizeof(png_byte);
	*image_data = malloc(size);
	if(!(*image_data)) {
		error(0, errno, "malloc");
		return 1;
	}

	memcpy(*image_data, p->image_data, size);

	return 0;
}

extern int pngio_width(const struct pngio_t * restrict const p,
		       png_uint_32 * restrict const width)
{
	*width = p->width;

	return 0;
}

extern int pngio_height(const struct pngio_t * restrict const p,
			png_uint_32 * height)
{
	*height = p->height;

	return 0;
}

extern int pngio_bit_depth(const struct pngio_t * restrict const p,
			   int * restrict const bit_depth)
{
	*bit_depth = p->bit_depth;

	return 0;
}

extern int pngio_color_type(const struct pngio_t * restrict const p,
			   int * restrict const color_type)
{
	*color_type = p->color_type;

	return 0;
}

/* local functions */
static int cmp_sig(FILE * f)
{
	png_byte * sig = malloc((SIZE_SIG + 1) * sizeof(png_byte));
	if(!(sig)) {
		error(0, errno, "malloc");
		return 1;
	}

	/* read the first SIZE_SIG bytes of the file */
	size_t n = fread( (void *) sig, SIZE_SIG_ELEM, SIZE_SIG, f);
	if(n == 0) {
		free(sig);
		return 1;
	}

	/* test that the file is actually a PNG file */
	int is_png = !(png_sig_cmp(sig, 0, SIZE_SIG));
	if(!(is_png)) {
		free(sig);
		return 1;
	}

	free(sig);

	return 0;
}

static int read_init(struct pngio_meta_t * restrict pm)
{
	pm->png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if(!(pm->png)) {
		error(0, errno, "png_create_read_struct");
		return 1;
	}

	pm->info = png_create_info_struct(pm->png);
	if(!(pm->info)) {
		png_destroy_read_struct(&pm->png, (png_infopp) NULL, (png_infopp) NULL);
		error(0, errno, "png_create_info_struct");
		return 1;
	}

	pm->end = png_create_info_struct(pm->png);
	if(!(pm->end)) {
		png_destroy_read_struct(&pm->png, &pm->info, (png_infopp) NULL);
		error(0, errno, "png_create_info_struct");
		return 1;
	}

	/* set jump for libpng error reporting */
	if(setjmp(png_jmpbuf(pm->png))) {
		png_destroy_read_struct(&pm->png, &pm->info, &pm->end);
		return 1;
	}

	return 0;
}

static int read_io_init(struct pngio_meta_t * restrict const pm,
			const char * restrict const filename, FILE ** file)
{
	FILE * f = fopen(filename, "rb");
	if(!(f)) {
		error(0, errno, "fopen");
		return 1;
	}

	if(cmp_sig(f) != 0) {
		fclose(f);
		return 1;
	}

	/* initialize png reading */
	png_init_io(pm->png, f);

	/* we already read the first SIZE_SIG bytes */
	png_set_sig_bytes(pm->png, SIZE_SIG);

	*file = f;

	return 0;
}

static int read_header(struct pngio_t * restrict const p,
		       struct pngio_meta_t * restrict const pm)
{
	/* read up to the image data */
	png_read_info(pm->png, pm->info);

	/* get PNG header info */
	int n = png_get_IHDR(pm->png, pm->info, &p->width, &p->height, &p->bit_depth, &p->color_type,
			     NULL, NULL, NULL);

	if(n == 0) return 1;

	/* update the info struct */
	png_read_update_info(pm->png, pm->info);

	if(setjmp(png_jmpbuf(pm->png))) return 1;

	return 0;
}

static int read_image(struct pngio_t * restrict const p,
		      struct pngio_meta_t * restrict const pm)
{
	png_uint_32 rowbytes = png_get_rowbytes(pm->png, pm->info);
	if(rowbytes <= 0) return 1;

	/* allocate the image data */
	png_byte * image_data = malloc(rowbytes * p->height * sizeof(png_byte));
	if(!(image_data)) {
		error(0, errno, "malloc");
		return 1;
	}

	png_bytep * rows = malloc(p->height * sizeof(png_bytep));
	if(!(rows)) {
		error(0, errno, "malloc");
		free(image_data);
		return 1;
	}

	/* set the individual row pointers */
	unsigned int i = 0;
	for(i = 0; i < p->height; i++)
		*(rows + i) = image_data + i * rowbytes;

	png_read_image(pm->png, rows);
	p->rowbytes = rowbytes;
	p->image_data = image_data;
	p->rows = rows;

	return 0;
}

static int read_destroy(struct pngio_meta_t * restrict const pm)
{
	png_destroy_read_struct(&pm->png, &pm->info, &pm->end);

	return 0;
}

static int write_init(struct pngio_meta_t * restrict const pm)
{
	pm->png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if(!(pm->png)) {
		error(0, errno, "png_create_write_struct");
		return 1;
	}

	pm->info = png_create_info_struct(pm->png);
	if(!(pm->info)) {
		png_destroy_write_struct(&pm->png, (png_infopp) NULL);
		error(0, errno, "png_create_info_struct");
		return 1;
	}

	/* set jump for libpng error reporting */
	if(setjmp(png_jmpbuf(pm->png))) {
		write_destroy(pm);
		return 1;
	}

	return 0;
}

static int write_io_init(struct pngio_meta_t * restrict const pm,
			 const char * restrict const filename, FILE ** file)
{
	FILE * f = fopen(filename, "wb");
	if(!(f)) {
		error(0, errno, "open");
		return 1;
	}

	/* initialize png for writing */
	png_init_io(pm->png, f);

	png_set_compression_level(pm->png, Z_BEST_COMPRESSION);

	*file = f;

	return 0;
}

static int write_header(const struct pngio_t * restrict const p,
			struct pngio_meta_t * restrict const pm)
{
	png_set_IHDR(pm->png, pm->info, p->width, p->height, p->bit_depth, p->color_type,
		     PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT,
		     PNG_FILTER_TYPE_DEFAULT);

	/* write everything up to the image data */
	png_write_info(pm->png, pm->info);

	/* pack low-bit-depth pixels */
	png_set_packing(pm->png);

	return 0;
}

static int write_image(const struct pngio_t * restrict const p,
		       struct pngio_meta_t * restrict const pm)
{
	if(setjmp(png_jmpbuf(pm->png))) {
		write_destroy(pm);
		return 1;
	}

	png_uint_32 rowbytes = png_get_rowbytes(pm->png, pm->info);
	if(rowbytes <= 0) return 1;

	png_bytep * rows = malloc(p->height * sizeof(png_bytep));
	if(!(rows)) {
		error(0, errno, "malloc");
		return 1;
	}

	/* set the individual row pointers */
	unsigned int i = 0;
	for(i = 0; i < p->height; i++)
		*(rows + i) = p->image_data + i * rowbytes;

	png_write_image(pm->png, rows);
	free(rows);
	rows = NULL;

	png_write_end(pm->png, NULL);

	return 0;	
}

static int write_destroy(struct pngio_meta_t * restrict const pm)
{
	png_destroy_write_struct(&pm->png, &pm->info);

	return 0;
}
