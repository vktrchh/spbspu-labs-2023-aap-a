#include "DivWithoutRemCounter.hpp"

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
    return; //??
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