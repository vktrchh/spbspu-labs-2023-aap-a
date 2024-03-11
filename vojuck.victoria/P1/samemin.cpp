#include "samemin.hpp"
#include <stdexcept>
#include <iostream>
#include <limits>

vojuck::CounterSameMin::CounterSameMin():
  count_(1)
{}

void vojuck::CounterSameMin::operator()(int num, int &minElement)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (count_ == max_size)
  {
    throw std::logic_error("Sequence is too long =(((((");
  }
  if (minElement > num)
  {
    count_ = 1;
    minElement = num;
  }
  else if (minElement == num)
  {
    ++count_;
  }
}

size_t vojuck::CounterSameMin::operator()() const
{
  return count_;
}

