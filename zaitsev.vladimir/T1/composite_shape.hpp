#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"

namespace zaitsev
{
	class CompositeShape
	{
	public:
		CompositeShape();
		~CompositeShape();
		CompositeShape(const CompositeShape& other);
		CompositeShape& operator=(const CompositeShape& other);
		CompositeShape(CompositeShape&& other);
		CompositeShape& operator=(CompositeShape&& other);
		void push_back(Shape* shape);
		void pop_back();
		Shape& at(size_t pos);
		const Shape& at(size_t pos) const;
		Shape& operator[](size_t pos);
		const Shape& operator[](size_t pos) const;
		bool empty() const;
		size_t size() const;
	private:
		size_t size_;
		size_t capacity_;
		Shape** shapes_;
	};
}
#endif COMPOSITE_SHAPE_HPP