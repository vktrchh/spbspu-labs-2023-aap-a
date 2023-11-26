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
  char* arrayWithOutSpace = new char[size];
  int isSpace = 0;
  int indexArr = 0;
  for (int j = 0; j < k; j++)
  {
    if (std::isspace(string[j]))
    {
      if (isSpace == 0)
      {
        arrayWithOutSpace[indexArr++] = ' ';
        isSpace = 1;
      }
    }
    else
    {
      arrayWithOutSpace[indexArr++] = string[j];
      isSpace = 0;
    }
  }
  if (indexArr > 0 && arrayWithOutSpace[0] == ' ')
  {
    for (int j = 0; j < indexArr - 1; j++)
    {
      arrayWithOutSpace[j] = arrayWithOutSpace[j + 1];
    }
    indexArr--;
  }
  arrayWithOutSpace[indexArr] = '\0';
  std::cout << arrayWithOutSpace << "\n";
  delete[] string;
  delete[] arrayWithOutSpace;
  return 0;
}
