#ifndef INC_SEQ_HPP
#define INC_SEQ_HPP

#include <cstddef>
namespace lebedev
{
  struct IncSeqCounter
  {
    IncSeqCounter();
    void count(int curr_num);
    size_t get_result() const;
  private:
    size_t count_;
    int prev_num_;
  };
}
#endif
