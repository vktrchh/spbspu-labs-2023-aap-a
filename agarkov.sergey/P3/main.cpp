#include <iostream>
#include <stdexcept>
#include "inputCStr.hpp"
#include "fillNewRepStr.hpp"
#include "fillNewStrWithoutVow.hpp"

int main()
{
  char* c_str = nullptr;
  try
  {
    c_str = inputCStr(std::cin);
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
  std::cout << c_str << "\n";

  char* rep_str = nullptr;
  try
  {
    char* rep_str = new char[size/2 + 1];
    fillNewRepStr(c_str, rep_str);
    std::cout << rep_str << "\n";
  }
  catch (const std::bad_alloc& e)
  {
    delete[] c_str;
    delete[] rep_str;
    std::cerr << e.what() << "\n";
    return 1;
  }

  char* vow_str = nullptr;
  try
  {
    char* vow_str = new char[size];
    fillNewStrWithoutVow(c_str, vow_str);
    std::cout << vow_str << "\n";
  }
  catch (const std::bad_alloc& e)
  {
    delete[] c_str;
    delete[] rep_str;
    delete[] vow_str;
    std::cerr << e.what() << "\n";
    return 1;
  }
  delete[] c_str;
  delete[] rep_str;
  delete[] vow_str;
}
