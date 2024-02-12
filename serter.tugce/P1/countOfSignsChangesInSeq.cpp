#include "countOfSignsChangesInSeq.hpp"
#include <iostream>
#include <limits>
#include <algorithm>
#include <cstddef>

serter::CountOfSignsChangesInSeq::CountOfSignsChangesInSeq():
  currentNumber_(0),
  count_(0)
{}

void serter::CountOfSignsChangesInSeq::operator()(int number)
{
  size_t max_size = std::numeric_limits< size_t >::max();

  if (number == max_size)
  {
    throw std::logic_error("sequence is too long");
  }
  if (currentNumber_ >= 0 && number < 0)
  {
    ++count_;
  }
  currentNumber_ = number;
}

size_t serter::CountOfSignsChangesInSeq::operator()() const
{
  return count_;
}
