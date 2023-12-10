#include "NumberOfSequence.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

agarkov::NumberOfSequence::NumberOfSequence():
  t_(0),
  num_(0),
  num_last_(0)
{}

void agarkov::NumberOfSequence::operator()(int number)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  num_ = num;
  if ((num_last_ != 0) && (num_last_ % num_ == 0))
  {
    if (num_ == max_size)
    {
      throw std::logic_error("Sequence is too long\n");
    }
    ++num_;
  }
  num_last_ = num_;
}
size_t agarkov::NumberOfSequence::operator()() const

{
   return num_;
}
