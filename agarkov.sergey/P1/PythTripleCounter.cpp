#include "PythTripleCounter.hpp"

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
    count++;
  }
}

int agarkov::PythTripleCounter::getCount()
{
  return count;
}
