#include <futile/rawbuffer.h>

namespace futile {

RawBuffer::RawBuffer() { }

RawBuffer::RawBuffer(std::istream & in)
{
	this->read(in);
}

RawBuffer::~RawBuffer() { }

/* methods */
void RawBuffer::clear()
{
	this->data.clear();
}

void RawBuffer::read(std::istream & in)
{
	this->data.assign((std::istreambuf_iterator<char>(in)),
                          (std::istreambuf_iterator<char>()));
}

void RawBuffer::write(std::ostream & out) const
{
	std::copy(this->data.begin(), this->data.end(),
                  (std::ostreambuf_iterator<char>(out)));
}

/* interfaces */
RawBuffer * RawBuffer::clone() const
{
	RawBuffer * copy = new RawBuffer();
	copy->data = std::vector<char>(this->data);

	return copy;
}

}
