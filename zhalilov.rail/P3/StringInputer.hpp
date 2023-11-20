#ifndef STRING_INPUTER_HPP
#define STRING_INPUTER_HPP

#include <cstddef>

namespace zhalilov
{
  class StringInputer
  {
  public:
    StringInputer();
    char *operator()();
  private:
    char *m_string;
    size_t m_dataInd;
    size_t m_strSize;

    void resize();
  };
}

#endif
