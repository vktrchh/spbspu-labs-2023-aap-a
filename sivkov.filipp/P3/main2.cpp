#include <iostream>
#include <string>
#include "copyNum.hpp"
int main()
{
  char c = 0;
  size_t k1 = 0, k2 = 0, k3 = 0;
  size_t size = 20;
  char* string1 = new char[size];
  char* string2 = new char[size];
  using namespace sivkov;

  if (!string1 || !string2)
  {
    std::cerr << "Error with arrays" << "\n";
    delete[] string1;
    delete[] string2;
    return 1;
  }
  std::cin >> std::noskipws;
  int newlineCount = 0;
  while (std::cin >> c)
  {
    if (c == '\n')
    {
      newlineCount++;
    }
    if (newlineCount == 2)
    {
      break;
    }
    if (newlineCount == 0)
    {
      if (k1 == size - 1)
      {
        char* newstring1 = new char[size * 2];
        if (!newstring1)
        {
          std::cerr << "Error with array\n";
          delete[] string1;
          delete[] string2;
          return 1;
        }
        for (int j = 0; j < size - 1; j++)
        {
          newstring1[j] = string1[j];
        }
        delete[] string1;
        string1 = newstring1;
        size *= 2;
      }
      string1[k1++] = c;
    }
    else
    {
      if (k2 == size - 1)
      {
        char* newstring2 = new char[size * 2];
        if (!newstring2)
        {
          std::cerr << "Error with array\n";
          delete[] string1;
          delete[] string2;
          return 1;
        }
        for (int j = 0; j < size - 1; j++)
        {
          newstring2[j] = string2[j];
        }
        delete[] string2;
        string2 = newstring2;
        size *= 2;
      }
      if (c != '\n')
      {
      string2[k2++] = c;
      }
    }
  }
    string1[k1] = '\0';
    string2[k2] = '\0';
    char* finalString = new char[k1 + k2 + 1];

    copyNum(string1, string2, finalString, k1, k2, k3);

    std::cout << finalString << "\n";

    delete[] string1;
    delete[] string2;
    delete[] finalString;

    return 0;
}

