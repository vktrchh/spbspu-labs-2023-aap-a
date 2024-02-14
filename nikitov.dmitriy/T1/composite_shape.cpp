#include "composite_shape.hpp"

nikitov::CompositeShape::CompositeShape():
{}

nikitov::CompositeShape::CompositeShape(const CompositeShape& composition):
{}

nikitov::CompositeShape::CompositeShape(const CompositeShape&& composition):
{}

CompositeShape& nikitov::CompositeShape::operator=(CompositeShape& composition)
{

}

CompositeShape& nikitov::CompositeShape::operator=(CompositeShape&& composition)
{

}

Shape* nikitov::CompositeShape::operator[](size_t index)
{

}

const Shape* nikitov::CompositeShape::operator[](size_t index) const
{

}

void nikitov::CompositeShape::push_back(Shape* figure)
{

}

void nikitov::CompositeShape::pop_back()
{

}

Shape* nikitov::CompositeShape::at(size_t index)
{

}

const nikitov::CompositeShape::Shape* at(size_t index) const
{

}

size_t nikitov::CompositeShape::size() const
{

}

bool nikitov::CompositeShape::empty() const
{

}

double nikitov::CompositeShape::getArea() const
{

}

rectangle_t nikitov::CompositeShape::getFrameRect() const
{

}

void nikitov::CompositeShape::move(const point_t& point)
{

}

void nikitov::CompositeShape::move(double dx, double dy)
{

}

void nikitov::CompositeShape::scale(double ratio)
{

}


