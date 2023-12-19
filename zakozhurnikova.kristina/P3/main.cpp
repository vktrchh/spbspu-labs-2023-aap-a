#include <iostream>
#include "removeSpaces.h"

int main()
{
  size_t size = 20;
  char *buff = nullptr;
  char *string = nullptr;
  char c = '\0';
  size_t counter = 0;
  try
  {
    buff = new char[size]{'\0'};
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }

  while (std::cin.get(c))
  {
    if (counter == size - 1)
    {
      try
      {
        string = new char[size]{'\0'};
      }
      catch (const std::exception &e)
      {
        std::cerr << e.what() << '\n';
        delete[] buff;
        buff = nullptr;
        return 1;
      }
      for (size_t i = 0; i < size; i++)
      {
        string[i] = buff[i];
      }

      size *= 2;
      delete[] buff;
      buff = nullptr;
      try
      {
        buff = new char[size]{'\0'};
      }
      catch (const std::exception &e)
      {
        std::cerr << e.what() << '\n';
        delete[] string;
        string = nullptr;
      }
      for (size_t i = 0; i < size / 2; i++)
      {
        buff[i] = string[i];
      }
      delete[] string;
      string = nullptr;
    }
    buff[counter] = c;
    counter++;
    if (c == '\n')
    {
      break;
    }
  }
  if (buff[0] == '\n' || !buff[0])
  {
    std::cerr << "Empty string\n";
    delete[] buff;
    return 1;
  }
  char *tmp = nullptr;
  try
  {
    tmp = new char[size]{'\0'};
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    delete[] string;
    delete[] buff;
    return 1;
  }
  zakozhurnikova::removeSpaces(tmp, buff, size);
  char *head = tmp;
  while (*head)
  {
    std::cout << *head;
    head++;
  }
  std::cout << '\n';
  head = nullptr;
  delete[] tmp;
  delete[] buff;
  buff = nullptr;
  tmp = nullptr;
  return 0;
}
