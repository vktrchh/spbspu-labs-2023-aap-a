#ifndef OTHERSFUN_HPP
#define OTHERSFUN_HPP
#include "shape.hpp"
#include <iostream>

void outputFrameRectInfo(std::ostream& out, const Shape* shape);
void findCoefficient(double& a, double& b, double& c, const point_t ver1, const point_t ver2);
double findLine(const point_t& a, const point_t& b);

#endif
