#include "sub_max.hpp"
#include <limits>
#include <stdexcept>

lebedev::SubMaxValue::SubMaxValue():
  max_(0),
  sub_max_(0)
{}

void lebedev::SubMaxValue::compare(int curr_num)
{
  if (max_ == 0)
  {
    max_ = curr_num;
  }
  else if (sub_max_ == 0 && max_ != 0)
  {
    if (curr_num >= max_)
    {
      sub_max_ = max_;
      max_ = curr_num;
    }
    else
    {
      sub_max_ = curr_num;
    }
  }
  else if (curr_num >= max_)
  {
    sub_max_ = max_;
    max_ = curr_num;
  }
}

int lebedev::SubMaxValue::get_result() const
{
  if (sub_max_ == 0 || max_ == 0)
  {
    throw std::logic_error("Sequence is too short");
  }
  return sub_max_;
}
