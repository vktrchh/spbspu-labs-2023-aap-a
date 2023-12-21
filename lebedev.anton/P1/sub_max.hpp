#ifndef SUB_MAX_HPP
#define SUB_MAX_HPP

#include <cstddef>
namespace lebedev
{
  struct SubMaxValue
  {
    SubMaxValue();
    void compare(int curr_num);
    int get_result() const;
  private:
    int max_;
    int sub_max_;
    int counter_;
  };
}
#endif
