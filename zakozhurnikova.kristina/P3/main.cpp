#include <iostream>
#include <inputOperations.hpp>

int main()
{
  size_t size = 20;
  char *buff = nullptr;
  char *string = nullptr;
  try
  {
    string = zakozhurnikova::readString(std::cin, size);
    buff = new char[size]{0};
  }
  catch (const std::exception & e)
  {
    delete[] string;
    delete[] buff;
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
