#include "removing_vowels.hpp"

char* sivkov::removing_vowels(char* string)
{
  char vowels[10] = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u' };
  size_t length = 0;
  while (string[length] != '\0')
  {
    ++length;
  }

  size_t new_length = 0;

  for (size_t i = 0; i < length; ++i)
  {
    bool is_vowel = false;
    for (size_t j = 0; j < 10; ++j)
    {
      if (string[i] == vowels[j])
      {
        is_vowel = true;
        break;
      }
    }
    if (!is_vowel)
    {
      string[new_length] = string[i];
      ++new_length;
    }
  }
  string[new_length] = '\0';
  return string;
}
