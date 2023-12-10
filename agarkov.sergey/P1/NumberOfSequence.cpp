#include "NumberOfSequence.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

agarkov::NumberOfSequence::NumberOfSequence():
  t_(0),
  num_(0),
  num_last_(0)
{}

void agarkov::NumberOfSequence::operator()(int num)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  num_ = num;
  if ((num_last_ != 0) && (num_last_ % num_ == 0))
  {
    if (t_ == max_size)
    {
      throw std::logic_error("sequence is too long");
    }
    ++t_;
  }
  num_last_ = num;
}
size_t agarkov::NumberOfSequence::operator()() const
{
  return t_;
}

