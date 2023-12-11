#ifndef SAME_MIN_HPP
#define SAME_MIN_HPP
#include <cstddef>
#include <iostream>

namespace vojuck
{
  struct SequenceCounter
  {
    SequenceCounter();
    void operator()(int number, int &minElement);
    size_t operator()() const;
  private:
    size_t count_;
  };
}

#endif
