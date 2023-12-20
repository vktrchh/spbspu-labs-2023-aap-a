#include "ring.hpp"
#include <stdexcept>

const double PI = 3.1415;

novokhatskiy::Ring::Ring(const point_t& center, double radius1, double radius2)
{
	if ((radius1 < 0.0) && (radius2 < 0.0))
	{
		throw std::invalid_argument("Ring radiuses are wrong\n");
	}
	frameRect_.pos = center;
	if (radius1 > radius2)
	{
		frameRect_.height = radius1 * 2;
		frameRect_.width = radius1 * 2;
	}
	else
	{
		frameRect_.height = radius2 * 2;
		frameRect_.width = radius2 * 2;
	}

}
double novokhatskiy::Ring::getArea() const
{
	return PI * frameRect_.width * frameRect_.height;
}
rectangle_t novokhatskiy::Ring::getFrameRect() const
{
	return frameRect_;
}
void novokhatskiy::Ring::move(const point_t& point)
{
	frameRect_.pos = point;
	center_ = point;
}
void novokhatskiy::Ring::move(double x, double y) 
{
	frameRect_.pos = { frameRect_.pos.x + x, frameRect_.pos.y + y };
}
void novokhatskiy::Ring::scale(const point_t& t, double ratio)
{
	if (ratio < 0.0)
	{
		std::invalid_argument("The ratio can't be negative\n");
	}
	frameRect_.height *= ratio;
	frameRect_.width *= ratio;
	radius1_ *= ratio;
	radius2_ *= ratio;

}
