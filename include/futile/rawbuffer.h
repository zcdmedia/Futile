/**
	@file		rawbuffer.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_RAWBUFFER_H_
#define FUTILE_RAWBUFFER_H_

#include <vector>
#include <istream>
#include <ostream>

#include <futile/cloneable.h>

namespace futile {

/**
	binary data buffer
 */
class RawBuffer : public Cloneable<RawBuffer *> {
public:
	RawBuffer();
	explicit RawBuffer(std::istream & in);
	~RawBuffer();

	/* accessors */
	inline const std::vector<char> & get_data() { return this->data; }

	/* methods */
	void clear();
	void read(std::istream & in);
	void write(std::ostream & out) const;

	/* interfaces */
	virtual RawBuffer * clone() const;

private:
	std::vector<char> data;
};

}

#endif
