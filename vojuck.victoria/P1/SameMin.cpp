#include "SameMin.hpp"
#include <limits>
#include <stdexcept>

vojuck::SequenceCounter::SequenceCounter():
  count_(1)
{}

void vojuck::SequenceCounter::operator()(int num, int &minElement)
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

size_t vojuck::SequenceCounter::operator()() const
{
  return count_;
}

