#include "NumberOfSequence.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

agarkov::NumberOfSequence::NumberOfSequence():
  number_(0),
  first_number_(0),
  last_number_(0)
{}

void agarkov::NumberOfSequence::operator()(int number)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  first_number_ = number;
  if ((last_number_ != 0) && (last_number % first_number_ == 0))
  {
    if (number_ == max_size)
    {
      throw std::logic_error("Sequence is too long\n");
    }
    ++number_;
  }
  last_number_ = first_number_;
}
size_t agarkov::NumberOfSequence::operator()() const

{
   return number_;
}
