#include <iostream>
#include <iomanip>

int main()
{
  int capacity = 10;
  char * str = nullptr;
  str = new char[capacity]{};
  int i = 0;
  char curr_char = 0;
  std::cin >> std::noskipws;
  while ((std::cin >> curr_char) && (i < capacity))
  {
    str[i] = curr_char;
    if (curr_char == '\n')
    {
      str[i] = '\0';
      break;
    }
    if (i == capacity - 1)
    {
      char * str_temp = new char[capacity]{};
      for (int j = 0; j < i; ++j)
      {
        str_temp[j] = str[j];
      }
      delete [] str;
      capacity += 10;
      str = new char[capacity]{};
      for (int j = 0; j < i; ++j)
      {
        str[j] = str_temp[j];
      }
      delete [] str_temp;
    }
    ++i;
  }
// for tests

/*  for (int k = 0; k < capacity; ++k)
  {
    std::cout << str[k] << " ";
  }
  std::cout << "\n" << capacity << "\n";*/
  delete [] str;
}
