#include "createalphabet.hpp"

size_t piyavkin::createAlphabet(bool * const alphabet, char * line, size_t length)
{
  size_t count = 0;
  for (size_t i = 0; i < length; ++i)
  {
    if (line[i] >= 'a' && line[i] <= 'z')
    {
      int symbol = line[i] - 'a';
      if (alphabet[symbol] == false)
      {
        ++count;
      }
      alphabet[symbol] = true;
    }
  }
  return 26-count;
}
