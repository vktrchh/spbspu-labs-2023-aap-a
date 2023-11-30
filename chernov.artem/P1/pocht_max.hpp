#ifndef POCHT_MAX_HPP
#define POCHT_MAX_HPP
#include <cstddef>

namespace chernov
{
  struct AlmostMax
  {
    AlmostMax();
    void operator()(int number);
    int operator()() const;
  private:
    void schetPremaxim(int number);
    int premaxim_;
    int maxim_;
  };
}

#endif
