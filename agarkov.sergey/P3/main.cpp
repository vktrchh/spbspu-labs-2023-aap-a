#include <iostream>
#include "inputCStr.hpp"
#include "fillNewRepStr.hpp"
#include "fillNewStrWithoutVow.hpp"

int main()
{
  char* c_str = nullptr;
  try
  {
    c_str = inputCString(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  size_t size = 0;
  while (c_str[size] != '\0')
  {
    size++;
  }
  std::cout << c_string << "\n";

  char* rep_str = nullptr;
  char* vow_str = nullptr;
  try
  {
    char* rep_str = new char[size/2 + 1];
    char* vow_str = new char[size];
    fillNewRepStr(c_str, rep_str);
    fillNewStrWithoutVow(c_str, vow_str);
    std::cout << rep_str << "\n";
    std::cout << vow_str << "\n";
  }
  catch (const std::bad_alloc& e)
  {
    delete[] rep_str;
    delete[] vow_str;
    std::cerr << e.what() << "\n";
    return 1;
  }
  delete[] rep_str;
  delete[] vow_str;
}