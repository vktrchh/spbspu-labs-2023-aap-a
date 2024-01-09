#include "createline.hpp"

char* piyavkin::createLine(char* line)
{
  const size_t number_letters_alphabet = 26;
  char* alphabet = new char[number_letters_alphabet + 1] {};
  for (size_t i = 0; i < number_letters_alphabet; ++i)
  {
    alphabet[i] = static_cast<char>('a' + i);
  }
  alphabet[number_letters_alphabet] = '\0';
  size_t i = 0;
  size_t number_new_line = number_letters_alphabet;
  char* old_alphabet = nullptr;
  while (line[i] != '\0')
  {
    for (size_t j = 0; j < number_new_line; ++j)
    {
      if (alphabet[j] == line[i])
      {
        --number_new_line;
        old_alphabet = alphabet;
        alphabet = new char[number_new_line + 1] {};
        size_t count = 0;
        for (size_t p = 0; p < number_new_line + 1; ++p)
        {
          if (old_alphabet[p] != line[i])
          {
            alphabet[count++] = old_alphabet[p];
          }
        }
        delete[] old_alphabet;
        alphabet[number_new_line] = '\0';
      }
    }
    ++i;
  }
  return alphabet;
}
