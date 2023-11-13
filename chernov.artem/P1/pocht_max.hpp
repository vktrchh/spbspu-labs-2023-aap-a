#ifndef POCHT_MAX_HPP
#define POCHT_MAX_HPP
#include <cstddef>

namespace chernov
{
  struct PochtMax
  {
    PochtMax();
    void operator()(int number);
    int operator()() const;
  private:
    void schetPremaxim(int number);
    int premaxim_;
    int maxim_;
  };
}

#endif
