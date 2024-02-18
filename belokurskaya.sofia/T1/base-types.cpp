#include <cmath>
#include <iostream>

#include "base-types.hpp"

double belokurskaya::roundOff(double value)
{
  double absoluteValue = std::fabs(value);
  double floorValue = std::floor(absoluteValue);
  double fracPart = absoluteValue - floorValue;

  double adjustment = 0.0;
  if (fracPart <= 0.25)
  {
    adjustment = 0.0;
  }
  else if (fracPart > 0.25 && fracPart < 0.75)
  {
    adjustment = 0.5;
  }
  else
  {
    adjustment = 1.0;
  }

  double roundedValue = (value >= 0) ? (floorValue + adjustment) : -(floorValue + adjustment);
  return roundedValue;
}
