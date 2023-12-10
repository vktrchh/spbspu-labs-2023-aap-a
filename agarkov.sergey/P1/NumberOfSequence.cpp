#include "NumberOfSequence.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

agarkov::NumberOfSequence::NumberOfSequence():
  k_(0),
  num_(0),
  num_old_(0)
{}

void agarkov::NumberOfSequence::operator()(int num)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  num_ = num;
  if ((num_old_ != 0) && (num_old_ % num_ == 0))
  {
    if (k_ == max_size)
    {
      throw std::logic_error("sequence is too long");
    }
    ++k_;
  }
  num_old_ = num;
}
size_t agarkov::NumberOfSequence::operator()() const
{
  return k_;
}

