#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace novokhatskiy
{
	class Rectangle : public shape
	{

	public:
		Rectangle(const point_t& leftAngle, const point_t& rightAngle);
		virtual double getArea() const;
		virtual rectangle_t getFrameRect() const;
		virtual void move(const point_t& p);
		virtual void move(const double x, const double y);
		virtual void scale(const double scale);
	private:
		rectangle_t frameRect;
	};
}

#endif 
