#ifndef INPUT_OUTPUT_STRING
#define INPUT_OUTPUT_STRING

#include <iosfwd>
namespace erohin
{
  char* inputString(std::istream& input, char* str, const size_t iter_size);
  void outputString(std::ostream& output, char* str);
}

#endif
