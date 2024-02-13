#include <cstddef>
#include "removing_vowels.hpp"

void sivkov::removing_vowels(char* string)
{
  const char vowels[11] = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u', '\0' };
  size_t oldIndex = 0;
  size_t newIndex = 0;
  while (string[oldIndex] != '\0')
  {
    bool isVowel = false;
    for (size_t i = 0; i < 10; ++i)
    {
      if (string[oldIndex] == vowels[i])
      {
        isVowel = true;
        break;
      }
    }
    if (!isVowel)
    {
      string[newIndex] = string[oldIndex];
      ++newIndex;
    }
    ++oldIndex;
  }
  string[newIndex] = '\0';
}
