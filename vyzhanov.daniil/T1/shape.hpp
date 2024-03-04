#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace vyzhanov
{
    class Shape
    {
        virtual ~Shape() = default;
        virtual double getArea() const = 0;
        virtual rectangle_t getFrameRect() const = 0;
        virtual void move(const point_t& point) = 0;
        virtual void move(const double mx, const double my) = 0;
        virtual void scale(const double ratio);
    };
}

#endif
