#include "removeVowels.hpp"
#include <cstddef>

char* chernov::removeVowels(char* input, char* stringWithVowelsRemoved, size_t sizeOfInput)
{
  size_t j = 0;
  bool flag = false;
  char vowels[6] = {'a', 'y', 'e', 'u', 'i', 'o'};
  for (size_t i = 0; i < sizeOfInput; i++)
  {
    for (int k = 0; k < 6; k++)
    {
      if (input[i] == vowels[k])
      {
        flag = true;
	break;
      }
    }
    if (flag == false)
    {
      stringWithVowelsRemoved[j] = input[i];
      j++;
    }
    flag = false;
  }
  return stringWithVowelsRemoved;
}
