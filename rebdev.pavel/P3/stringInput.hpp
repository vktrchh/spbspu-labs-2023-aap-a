#ifndef STRINGINPUT_HPP
#define STRINGINPUT_HPP

#include <iostream>
namespace rebdev
{
  char * inputStr(std::istream & input, char * str);
  char * newStr(char * oldStr, size_t size);
}

#endif
