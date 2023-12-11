#ifndef AFT_MAX_HPP
#define AFT_MAX_HPP
#include <cstddef>
#include <iostream>

namespace vojuck
{
  struct SequenceCounter
  {
    SequenceCounter();
    void operator()(int number, int &maxElement);
    size_t operator()() const;
  private:
    size_t count_;
  };
}
#endif
