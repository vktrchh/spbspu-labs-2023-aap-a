#ifndef INPUTLINE
#define INPUTLINE
#include <istream>
namespace piyavkin
{
  char * inputLine(std::istream & in, size_t & length);
  void copyLine(char * old_line, char * new_line, size_t length);
}
#endif
