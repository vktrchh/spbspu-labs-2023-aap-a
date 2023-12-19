#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace novokhatskiy
{
	class shape
	{
	public :
		virtual double getArea() const = 0;
		virtual rectangle_t getFrameRect() const = 0;
		virtual void move(const point_t& p) = 0;
		virtual void move(const double x, const double y) = 0;
		virtual void scale(const double scale) = 0;
	};
}
#endif 
