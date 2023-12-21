#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>

namespace nikitov
{
  bool enterBuffer(char buffer[], std::istream& input, size_t& i, size_t bufferSize);

  void moveBuffer(char buffer[], char* actualArray, size_t arraySize, size_t bufferSize);

  char* increaseArray(char* actualArray, char* tempArray, size_t arraySize, size_t bufferSize);
}
#endif