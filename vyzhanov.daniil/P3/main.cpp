#include <iostream>
#include "InputString.hpp"
#include "DeleteAllNumbers.hpp"
#include "CountUniqueLetters.hpp"

int main()
{
  char* string = nullptr;
  char* newString = nullptr;
  size_t sizeOfString = 0;
  try
  {
    string = vyzhanov::inputString(std::cin);
    if (string[0] == '\0')
    {
      delete[] string;
      std::cerr << "Empty string!" << "\n";
      return 1;
    }
    while (string[sizeOfString])
    {
      sizeOfString++;
    }
    newString = new char[sizeOfString];
    std::cout << vyzhanov::deleteAllNumbers(string, newString) << "\n";
    std::cout << vyzhanov::countUniqueLetters(string) << "\n";
  }
  catch (const std::bad_alloc& e)
  {
    delete[] string;
    delete[] newString;
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
    delete[] string;
    delete[] newString;
}
