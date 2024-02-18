#include "isConsonat.hpp"
#include <cstddef>

bool stepanov::isConsonat(char symbol)
{
  const char* listVowels = "AEIOUaeiou";
  bool flag = true;
  for (size_t j = 0; listVowels[j] != '\0'; ++j)
  {
    if (symbol == listVowels[j])
    {
      flag = false;
      break;
    }
  }
  return flag;
}
