#include <iostream>
#include "extractChars.hpp"
#include "addLat.hpp"
#include "inputString.hpp"

int main()
{
  using namespace isaychev;
  size_t capacity = 10;
  size_t length1 = 0;
  size_t & linkToCap = capacity;
  size_t & linkToLgth = length1;
  char * str = nullptr;
  try
  {
    str = inputString(std::cin, linkToLgth, linkToCap);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what() << "\n";
    delete [] str;
    return 2;
  }
//  std::cout << str<< " " << length1 << " " << capacity << "\n";
  const char * str2 = "AFD12hd";
  size_t length2 = 0;
  while (str2[length2] != '\0')
  {
    length2++;
  }
  char * str_after_extr = nullptr;
  try
  {
    str_after_extr = new char[capacity]{};
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "can't allocate memory for final string for 1st task\n";
    delete [] str;
    return 1;
  }
  extractChars(str, str2, str_after_extr, length1, length2);
  std::cout << str_after_extr << "\n";
  delete [] str_after_extr;
  char * strLat = nullptr;
  try
  {
    strLat = new char[length1 + length2]{};
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "can't allocate memory for final string for 2nd task\n";
    delete [] str;
    return 1;
  }
  addLat(str, str2, strLat, length1, length2);
  std::cout << strLat << "\n";
  delete [] strLat;
  delete [] str;
}
