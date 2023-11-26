#ifndef INPUT_H
#define INPUT_H
#include <cstddef>

namespace zaitsev
{
  char* readStr();
  void resizeStr(char** str, size_t old_size, size_t new_size);
}
#endif
