#include "aftmax.hpp"
#include <stdexcept>
#include <limits>
#include <iostream>

vojuck::CounterAftMax::CounterAftMax():
  count_(0)
{}

void vojuck::CounterAftMax::operator()(int num)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (count_ == max_size - 1)
  {
    throw std::logic_error("Sequence is too long =(((((");
  }
  if (maxElement < num)
  {
    count_ = 0;
    maxElement = num;
  }
  else
  {
    ++count_;
  }
}

size_t vojuck::CounterAftMax::operator()() const
{
  return count_;
}
