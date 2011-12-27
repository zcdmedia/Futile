/**
	@file		pngio.h
	@author		Matthew Hinkle
	@brief		libpng wrapper
 */

#ifndef __PNGIO_T_H__
#define __PNGIO_T_H__

#include <png.h>

#ifdef __cplusplus
extern "C" {
#endif

/* pngio_t data structure */
struct pngio_t {
	png_bytep * rows;
	png_byte * image_data;
	png_uint_32 width;
	png_uint_32 height;
	png_uint_32 rowbytes;
	int bit_depth;
	int color_type;
};

/* intialization and cleanup */
extern int pngio_init(struct pngio_t *);

extern int pngio_destroy(struct pngio_t *);

extern int pngio_free(struct pngio_t **);

/* reading */
extern int pngio_read(struct pngio_t *, const char *);

/* writing */
extern int pngio_write(const struct pngio_t * p, const char *);

/* facilitative functions */
extern int pngio_is_png(const char *, int *);

/* field access */
extern int pngio_image_data(const struct pngio_t *, png_byte **);

extern int pngio_width(const struct pngio_t *, png_uint_32 *);

extern int pngio_height(const struct pngio_t *, png_uint_32 *);

extern int pngio_bit_depth(const struct pngio_t *, int *);

extern int pngio_color_type(const struct pngio_t *, int *);

static inline int pngio_size(const struct pngio_t * p)
{
	return p->rowbytes * p->height * sizeof(png_byte);
}

#ifdef __cplusplus
}
#endif

#endif
