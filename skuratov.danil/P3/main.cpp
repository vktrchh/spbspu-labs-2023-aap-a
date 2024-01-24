#include "mergeTwoLines.hpp"
#include "transformInputString.hpp"
#include "removeDuplicate.hpp"
#include <cstddef>
#include <iostream>
#include <cstring>

int main()
{
  using namespace skuratov;
  size_t size = 10;
  std::cout << "1.Enter first line: ";

  char* input1 = new char[size];
  input1 = transformInputString(input1, size);

  std::cout << "Enter second line: ";

  char* input2 = new char[size];
  input2 = transformInputString(input2, size);
  if (input1 == nullptr)
  {
    delete[] input1;
    return 1;
  }
  char* line1 = new char[size];
  char* line2 = new char[size];
  char* line3 = new char[size];
  line3 = mergeTwoLines(input1, input2);

  std::cout << "Result merging: " << line3 << '\n';
  delete[] line1;
  delete[] line2;
  delete[] line3;

  std::cout << "2.Enter first line: ";

  char* input3 = new char[size];
  input3 = transformInputString(input3, size);

  std::cout << "Enter second line: ";

  char* input4 = new char[size];
  input4 = transformInputString(input4, size);
  if (input3 == nullptr)
  {
    delete[] input3;
    return 1;
  }
  char* line4 = new char[size];
  char* line5 = new char[size];
  char* result = removeDuplicate(input3, input4);

  std::cout << "Result after removing duplicates: " << result;
  delete[] line4;
  delete[] line5;
  delete[] result;
}
