#include "pocht_max.hpp"
#include <limits>
#include <stdexcept>

chernov::PochtMax::PochtMax():
  premaxim_(0),
  maxim_(0)
{}

void chernov::PochtMax::operator()(int number)
{
  if (maxim_ == 0)
  {
    maxim_ = number;
  }
  else if (maxim_ > 0)
  {
    if (number > maxim_)
    {
      premaxim_ = maxim_;
      maxim_ = number;
    }
    else if (number < maxim_)
    {
      if (premaxim_ < number)
      {
        premaxim_ = number;
      }
    }
  }
}

int chernov::PochtMax::operator()() const
{
  return premaxim_;
}
