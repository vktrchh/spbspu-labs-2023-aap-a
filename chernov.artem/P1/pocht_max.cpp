#include "pocht_max.hpp"
#include <stdexcept>
#include <limits>

chernov::AlmostMax::AlmostMax():
  premaxim_(0),
  maxim_(0)
{}

void chernov::AlmostMax::operator()(int number)
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

int chernov::AlmostMax::operator()() const
{
  return premaxim_;
}
