#ifndef NUMBEROFSEQUENCE_HPP
#define NUMBEROFSEQUENCE_HPP
#include <cstddef>
namespace agarkov
{
  struct NumberOfSequence
  {
    NumberOfSequence();
    void operator()(int number);
    size_t operator()() const;
  private:
    size_t number_;
    int first_number_;
    int last_number_;
  };
}
#endif
