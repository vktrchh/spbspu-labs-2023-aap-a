#include "ellipse.hpp"
#include <stdexcept>

const double PI = 3.1415;

novokhatskiy::Ellipse::Ellipse(const point_t& center, double vert, double horizon)
{																			
	if ((vert < 0.0) && (horizon < 0.0))
	{
		throw std::invalid_argument("Ellipse radiuses are wrong\n");
	}
	frameRect_.height = vert * 2;
	frameRect_.width = horizon * 2;
	center_ = center;
	vert_ = vert;
	horizon_ = horizon;
}

double novokhatskiy::Ellipse::getArea() const
{
	return PI * frameRect_.height * frameRect_.width;
}

rectangle_t novokhatskiy::Ellipse::getFrameRect() const
{
	return frameRect_;
}

void novokhatskiy::Ellipse::move(const point_t& point)
{
	frameRect_.pos = point;
	center_ = point;
}

void novokhatskiy::Ellipse::move(double x, double y)
{
	frameRect_.pos = { frameRect_.pos.x + x, frameRect_.pos.y + y };
}

void novokhatskiy::Ellipse::scale(const point_t& t , double ratio)
{
	if (ratio < 0.0)
	{
		throw std::invalid_argument("The ratio can't be negative\n");
	}
	frameRect_.height *= ratio;
	frameRect_.width *= ratio;
	vert_ *= ratio;
	horizon_ *= ratio;
}
