#include "rectangle.hpp"

novokhatskiy::Rectangle::Rectangle(const point_t& leftAngle, const point_t& rightAngle)
{
	frameRect.width = rightAngle.x - leftAngle.x;
	frameRect.height = rightAngle.y - leftAngle.y;
	double posX = leftAngle.x + frameRect.width / 2;
	double posY = leftAngle.y + frameRect.height / 2;
	frameRect.pos = { posX, posY };
}
