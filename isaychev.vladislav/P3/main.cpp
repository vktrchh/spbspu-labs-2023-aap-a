#include <iostream>
#include <iomanip>
#include <cstddef>

int main()
{
  int capacity = 10;
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
      for (int j = 0; j < length1; ++j)
      {
        str_temp[j] = str[j];
      }
      delete [] str;
      capacity += 10;
      str = new char[capacity]{};
      for (int j = 0; j < length1; ++j)
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
  str_after_extr = new char[capacity]{};

// for tests

/*  for (int k = 0; k < capacity; ++k)
  {
    std::cout << str[k] << " ";
  }
  std::cout << "\n" << capacity << "\n";*/
  delete [] str_after_extr;
  delete [] str;
}
