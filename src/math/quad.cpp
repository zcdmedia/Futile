#include <futile/math/quad.h>

namespace futile {

Quad::Quad() : p1(), p2(), p3(), p4() { }

Quad::Quad(const Point2 & p1, const Point2 & p2,
           const Point2 & p3, const Point2 & p4)
{
	this->p1.set(p1);
	this->p2.set(p2);
	this->p3.set(p3);
	this->p4.set(p4);
}

/* interfaces */
bool Quad::equals(const Quad & q) const
{
	return this->p1.equals(q.p1)
               && this->p2.equals(q.p2)
               && this->p3.equals(q.p3)
               && this->p4.equals(q.p4);
}

}
