#include <iostream>
#include <cstddef>

int main()
{
  using namespace chernov;
  size_t sizeOfInput = 20;
  char* input = new char[sizeOfInput]{};
  delete[] input;
}
