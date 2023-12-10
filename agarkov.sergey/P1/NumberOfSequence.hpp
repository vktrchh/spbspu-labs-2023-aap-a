#ifndef NUMBEROFSEQUENCE_HPP
#define NUMBEROFSEQUENCE_HPP
#include <cstddef>
namespace agarkov
{
  struct NumberOfSequence
  {
    NumberOfSequence();
    void operator()(int num);
    size_t operator()() const;
  private:
    size_t t_;
    int num_;
    int num_last_;
  };
}
#endif
