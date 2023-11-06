#ifndef PIFTRIPLES_COUNTER_HPP
#define PIFTRIPLES_COUNTER_HPP
#include <cstddef>

namespace chernov
{
  struct PifTriples_counter
  {
    PifTriples_counter();
    void operator()(int number);
    size_t operator()() const;
  private:
    const char* PifTriple(int number);
    int perv_el_;
    int vtor_el_;
    size_t piftriples_;
  };
}

#endif
