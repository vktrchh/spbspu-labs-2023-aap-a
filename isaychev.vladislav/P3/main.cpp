#include <iostream>
#include <iomanip>
#include <cstddef>
#include "extractChars.hpp"

int main()
{
  size_t capacity = 10;
  char * str = nullptr;
  str = new char[capacity]{};
  char curr_char = 0;
  size_t length1 = 0;
  std::cin >> std::noskipws;
  while ((std::cin >> curr_char) && (length1 < capacity))
  {
    str[length1] = curr_char;
    if (curr_char == '\n')
    {
      str[length1] = '\0';
      break;
    }
    if (length1 == capacity - 1)
    {
      char * str_temp = new char[capacity]{};
      for (size_t j = 0; j < capacity; ++j)
      {
        str_temp[j] = str[j];
      }
      delete [] str;
      capacity += 10;
      str = new char[capacity]{};
      for (size_t j = 0; j < capacity; ++j)
      {
        str[j] = str_temp[j];
      }
      delete [] str_temp;
    }
    length1++;
  }
  const char * str2 = "AFD12hd";
  size_t length2 = 0;
  while (str2[length2] != '\0')
  {
    length2++;
  }
  char * str_after_extr = new char[capacity]{};
  extractChars(str, str2, str_after_extr, length1, length2);
  std::cout << str_after_extr << "\n";
  delete [] str_after_extr;
  delete [] str;
}
