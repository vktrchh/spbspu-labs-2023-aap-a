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
  if (pifTriple(number) == 1 && perv_el_ != 0 && vtor_el_ != 0)
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

bool chernov::PifTriplesCounter::pifTriple(int number)
{
  int a = perv_el_;
  int b = vtor_el_;
  int c = number;
  return (c * c == (a * a + b * b));
}

size_t chernov::PifTriplesCounter::operator()() const
{
  return piftriples_;
}
