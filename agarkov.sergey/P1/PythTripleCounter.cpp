#include "PythTripleCounter.hpp"

#include <stdexcept>
#include <limits>
#include <cstddef>

agarkov::PythTripleCounter::PythTripleCounter():
  count(0),
  first(0),
  second(0),
  third(0)
{}

void agarkov::PythTripleCounter::operator()(int num)
{
  third = second;
  second = first;
  first = num;
  if ((first * first) == (second * second + third * third) && second > 0 && third > 0)
  {
    if (count == std::numeric_limits< size_t >::max())
    {
      throw std::logic_error("The upper limit size_t");
    }
    count++;
  }
}

int agarkov::PythTripleCounter::getCount() const
{
  return count;
}
