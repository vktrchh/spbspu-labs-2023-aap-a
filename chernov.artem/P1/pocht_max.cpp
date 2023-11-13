#include "pocht_max.hpp"
#include <limits>
#include <stdexcept>

chernov::PochtMax::PochtMax():
  propusk_(0),
  premaxim_(0),
  maxim_(0)
{}

void chernov::PochtMax::operator()(int number)
{
  if (maxim_ == 0)
  {
    maxim_ = number;
    propusk_ = 1;
  }
  else if (maxim_ > 0)
  {
    if (number > maxim_)
    {
      premaxim_ = maxim_;
      maxim_ = number;
      propusk_ = 2;
    }
    else if (number < maxim_)
    {
      if (premaxim_ < number)
      {
        premaxim_ = number;
        propusk_ = 2;
      }
    }
  }
}

int chernov::PochtMax::operator()() const
{
  return premaxim_;
}
