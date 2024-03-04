#include <iostream>
#include "inputCStr.hpp"
#include "fillNewRepStr.hpp"
#include "fillNewStrWithoutVow.hpp"

int main()
{
  char* c_str = nullptr;
  c_str = inputCStr(std::cin);
  std::cout << c_str << "\n";
  size_t size = 0;
  while (c_str[size] != '\0')
  {
    size++;
  }

  char* rep_str = new char[size/2 + 1];
  fillNewRepStr(c_str, rep_str);
  std::cout << rep_str << "\n";
  char* vow_str = new char[size];
  fillNewStrWithoutVow(c_str, vow_str);
  std::cout << vow_str << "\n";
}