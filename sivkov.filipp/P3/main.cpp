#include <iostream>

int main()
{
  char c = 0;
  size_t k = 0;
  int size = 20;
  char* string = new char[size];

  if (!string)
  {
    std::cerr << "Error with array" << "\n";
    return 1;
  }

  std::cin >> std::noskipws;
  while (std::cin >> c)
  {
    if ((k == 0) && (c == '\n'))
    {
      std::cerr << "Very small string\n";
      return 1;
    }

    string[k++] = c;
    if (c == '\n')
    {
      break;
    }
    else
    {
      if (k == size - 1)
      {
        char* newstring = new char[size * 2];
        if (!newstring)
        {
          std::cerr << "Error with array\n";
          delete[] string;
          return 1;
        }
        for (int j = 0; j < size - 1; j++)
        {
          newstring[j] = string[j];
        }
        delete[] string;
        string = newstring;
        size *= 2;
      }
    }

  }
  std::cout << string << "\n";
  delete[] string;
  return 0;
}
