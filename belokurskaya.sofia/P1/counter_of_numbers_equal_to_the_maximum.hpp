#ifndef COUNTER_OF_NUMBERS_EQUAL_TO_THE_MAXIMUM_HPP
#define COUNTER_OF_NUMBERS_EQUAL_TO_THE_MAXIMUM_HPP

#include <cstddef>
namespace belokurskaya
{
  struct CounterOfNumbersEqualToTheMaximum
  {
    CounterOfNumbersEqualToTheMaximum();
    void operator()(int number);
    size_t operator()() const;
  private:
    size_t count_;
    int max_;
    size_t count_max_;
  };
}
#endif
