#include "NumberOfSequence.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

agarkov::NumberOfSequence::NumberOfSequence():
  number_(0),
  lastnumber_(0)
{}

void agarkov::NumberOfSequence::operator()(int number)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  number_ = number;
  if ((lastnumber_ != 0) && (lastnumber % number_ == 0))
  {
    if (number_ == max_size)
    {
      throw std::logic_error("Sequence is too long\n");
    }
    ++number_;
  }
  lastnumber_ = number;
}
size_t agarkov::NumberOfSequence::operator()() const
{
  if (lastnumber_ == 0)
  {
    throw std::logic_error("Sequence is too short\n");
  }
  else
  {
   return number_;
  }
}
