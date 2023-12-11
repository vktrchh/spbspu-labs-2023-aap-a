#include "AftMax.hpp"
#include <limits>
#include <stdexcept>

vojuck::SequenceCounter::SequenceCounter():
   count_(0)
{}

void vojuck::SequenceCounter::operator()(int num, int &maxElement)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (count_ == max_size)
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

size_t vojuck::SequenceCounter::operator()() const
{
  return count_;
}
