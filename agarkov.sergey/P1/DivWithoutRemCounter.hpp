#ifndef DIVWITHOUTREMCOUNTER_HPP 
#define DIVWITHOUTREMCOUNTER_HPP 

#include <cstddef>

namespace agarkov
{
  struct DivWithoutRemCounter
  {
  public:
    DivWithoutRemCounter();
    void operator()(int cur);
    int getCount();
  private:
    int prev;
    size_t count;
  };
}

#endif
