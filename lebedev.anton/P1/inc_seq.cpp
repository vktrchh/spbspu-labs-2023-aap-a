#include "inc_seq.hpp"
#include <limits>
#include <stdexcept>

lebedev::IncSeqCounter::IncSeqCounter():
  count_(0),
  prev_num_(0)
{}

void lebedev::IncSeqCounter::count(int curr_num)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if ((curr_num > prev_num_) && (prev_num_ != 0))
  {
    if (count_ == max_size)
    {
      throw std::logic_error("Sequence is too long");
    }
    ++count_;
  }
  prev_num_ = curr_num;
}

size_t lebedev::IncSeqCounter::get_result() const
{
  return count_;
}
