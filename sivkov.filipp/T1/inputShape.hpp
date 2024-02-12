#ifndef INPUTSHAPE_HPP
#define INPUTSHAPE_HPP
#include "shape.hpp"
#include <iostream>

void inputRectangle(std::istream& in, Shape** shapes, size_t count);
void inputConcave(std::istream& in, Shape** shapes, size_t count);
void inputComplexQuad(std::istream& in, Shape** shapes, size_t count);
Shape** inputShape(std::istream& input, size_t& count);

#endif

