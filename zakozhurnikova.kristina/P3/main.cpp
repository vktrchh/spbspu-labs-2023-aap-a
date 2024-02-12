#include "removeSpaces.h"
#include <iostream>
#include <inputOperations.hpp>

int main()
{
  size_t size = 20;
  char *string = nullptr;
  try
  {
    string = zakozhurnikova::readString(std::cin, size);
  }
  catch (const std::exception & e)
  {
    delete[] string;
    std::cerr << "Error: " << e.what() << '\n';
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
    return 1;
  }
  zakozhurnikova::removeSpaces(tmp, string, size);
  char *head = tmp;
  while (*head)
  {
    std::cout << *head;
    head++;
  }
  std::cout << '\n';
  head = nullptr;
  delete[] tmp;
  delete[] string;
  return 0;
}
