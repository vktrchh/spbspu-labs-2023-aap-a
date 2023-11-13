#ifndef POCHT_MAX_HPP
#define POCHT_MAX_HPP
#include <cstddef>

namespace chernov
{
  struct PochtMax
  {
    PochtMax();
    void operator()(int number);
    size_t operator()() const;
  private:
    void schetPremaxim(int number);
    int propusk_;
    int premaxim_;
    int maxim_;
  };
}

#endif
