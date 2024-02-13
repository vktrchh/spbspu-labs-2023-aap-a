#include "DivWithoutRemCounter.hpp"

#include <stdexcept>

agarkov::DivWithoutRemCounter::DivWithoutRemCounter():
  prev(0),
  count(0)
{}

void agarkov::DivWithoutRemCounter::operator()(int num)
{
  if (prev == 0)
  {
    prev = num;
    return;
  }
  if (prev < 0)
  {
    throw std::logic_error("Division by remainder by a negative number");
  }
  if (num % prev == 0)
  {
    count++;
  }
  prev = num;
}

int agarkov::DivWithoutRemCounter::getCount()
{
  return count;
}
