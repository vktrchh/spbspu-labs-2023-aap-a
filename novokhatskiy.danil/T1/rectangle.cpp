#include "rectangle.hpp"
#include <stdexcept>

novokhatskiy::Rectangle::Rectangle(const point_t& leftAngle, const point_t& rightAngle)
{
	if ((leftAngle.y >= leftAngle.x) || (rightAngle.y >= rightAngle.x))
	{
		throw std::invalid_argument("Wrong arguments\n");
	}
	frameRect_.width = rightAngle.x - leftAngle.x;
	frameRect_.height = rightAngle.y - leftAngle.y;
	double posX = leftAngle.x + frameRect_.width / 2;
	double posY = leftAngle.y + frameRect_.height / 2;
	frameRect_.pos = { posX, posY };
}
double novokhatskiy::Rectangle::getArea() const
{
	return frameRect_.height * frameRect_.width;
}
rectangle_t novokhatskiy::Rectangle::getFrameRect() const
{
	return {frameRect_.width, frameRect_.width, frameRect_.pos };
}
void novokhatskiy::Rectangle::move(const point_t& p)
{
	frameRect_.pos = p;
}
void novokhatskiy::Rectangle::move(double x, double y)
{
	frameRect_.pos.x += x;
	frameRect_.pos.y += y;
}
void novokhatskiy::Rectangle::scale(const point_t& t, double ratio)
{
	if (ratio <= 0.0)
	{
		throw std::invalid_argument("The ratio can't be negative or zero\n");
	}

	frameRect_.width *= ratio;
	frameRect_.height *= ratio;
	leftAngle_.x = (leftAngle_.x - frameRect_.pos.x) * (ratio - 1);
	leftAngle_.y = (leftAngle_.y - frameRect_.pos.y) * (ratio - 1);
	rightAngle_.x = (rightAngle_.x - frameRect_.pos.x) * (ratio - 1);
	rightAngle_.y = (rightAngle_.y - frameRect_.pos.y) * (ratio - 1);

	leftAngle_.x = (leftAngle_.x - t.x) * (ratio - 1);
	leftAngle_.y = (leftAngle_.y - t.y) * (ratio - 1);
	rightAngle_.x = (rightAngle_.x - t.x) * (ratio - 1);
	rightAngle_.y = (rightAngle_.y - t.y) * (ratio - 1);
	frameRect_.pos.x = (frameRect_.pos.x - t.x) * (ratio - 1);
	frameRect_.pos.y = (frameRect_.pos.y - t.y) * (ratio - 1);
}
novokhatskiy::Rectangle::~Rectangle() = default;
