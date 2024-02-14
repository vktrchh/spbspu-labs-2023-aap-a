#include "read_string.h"

#include <iostream>
#include <cctype>

char * convertToLowercase(char * destination, const char * source)
{
  char * destinationBegin = destination;
  for ( ; *source != '\0'; destination++, source++)
  {
    *destination = tolower(*source);
  }

  return destinationBegin;
}

int main()
{
  char * string = nullptr;
  try
  {
    string = kovtun::readString(std::cin);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }

  std::cout << string;

  return 0;
}
