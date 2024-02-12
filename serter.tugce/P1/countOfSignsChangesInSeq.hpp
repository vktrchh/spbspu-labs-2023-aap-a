#ifndef countOfSignsChangesInSeq_hpp
#define countOfSignsChangesInSeq_hpp

#include <cstddef>
namespace serter
{
  struct CountOfSignsChangesInSeq
  {
    CountOfSignsChangesInSeq();
    void operator()(int);
    size_t operator()() const;
    size_t countOfMembersOfSeq_;
  private:
    int currentNumber_;
    size_t count_;
  };
}

#endif

