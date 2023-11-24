#include <iostream>
#include <iomanip>
#include <cstddef>
#include "extractChars.hpp"

int main()
{
  size_t capacity = 10;
  char * str = nullptr;
  try
  {
    str = new char[capacity]{};
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "can't allocate memory for first string\n";
    return 1;
  }
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
      char * str_temp = nullptr;
      try
      {
        str_temp = new char[capacity]{};
      }
      catch (const std::bad_alloc &)
      {
        std::cerr << "can't allocate memory for additional string\n";
        delete [] str;
        return 1;
      }
      for (size_t j = 0; j < capacity; ++j)
      {
        str_temp[j] = str[j];
      }
      delete [] str;
      capacity += 10;
      try
      {
        str = new char[capacity]{};
      }
      catch (const std::bad_alloc &)
      {
        std::cerr << "can't allocate memory for first string\n";
        delete [] str_temp;
        return 1;
      }
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
  char * str_after_extr = nullptr;
  try
  {
    str_after_extr = new char[capacity]{};
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "can't allocate memory for final string for 1st task\n";
    delete [] str;
    return 1;
  }
  extractChars(str, str2, str_after_extr, length1, length2);
  std::cout << str_after_extr << "\n";
  delete [] str_after_extr;
  delete [] str;
}
