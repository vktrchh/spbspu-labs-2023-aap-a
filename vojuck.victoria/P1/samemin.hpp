#ifndef SAME_MIN_HPP
#define SAME_MIN_HPP
#include <cstddef>

namespace vojuck
{
  struct CounterSameMin
  {
    CounterSameMin();
    void operator()(int number);
    size_t operator()() const;
  private:
    int minElement_;
    size_t count_;
  };
}

#endif
