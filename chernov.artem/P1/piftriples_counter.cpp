#include "piftriples_counter.hpp"
#include <limits>
#include <stdexcept>

chernov::PifTriplesCounter::PifTriplesCounter():
  piftriples_(0),
  perv_el_(0),
  vtor_el_(0)
{}

void chernov::PifTriplesCounter::operator()(int number)
{
  if (PifTriple(number) == 1 && perv_el_ != 0 && vtor_el_ != 0)
  {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (piftriples_ == max_size)
    {
      throw std::logic_error("Sequence is too long");
    }
    ++piftriples_;
  }
  perv_el_ = vtor_el_;
  vtor_el_ = number;
}

int chernov::PifTriplesCounter::PifTriple(int number)
{
  int a = perv_el_;
  int b = vtor_el_;
  int c = number;
  if ((a * a + b * b) == c * c)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

size_t chernov::PifTriplesCounter::operator()() const
{
  return piftriples_;
}
