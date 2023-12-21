#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>

namespace nikitov
{
  bool enterIntoTheBuffer(char buffer[], std::istream& input, size_t& i, size_t bufferSize);

  void movingFromBuffer(char buffer[], char* actualArray, size_t arraySize, size_t bufferSize);

  char* increaseArray(char* actualArray, char* tempArray, size_t arraySize, size_t bufferSize);
}
#endif
