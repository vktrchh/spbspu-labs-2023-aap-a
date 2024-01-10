#include "mergeTwoLines.hpp"
#include "transformInputString.hpp"
#include "removeDuplicate.hpp"
#include <cstddef>
#include <iostream>
#include <cstring>

int main()
{
  size_t size = 10;
  std::cout << "Enter first line: ";

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

  const int maxStringLength = 10;

  char str1[maxStringLength];
  char str2[maxStringLength];

  std::cout << "Enter the first string: ";
  std::cin >> str1;

  std::cout << "Enter the second string: ";
  std::cin >> str2;

  char* result = removeDuplicate(str1, str2);

  std::cout << "Result after removing duplicates: " << result;

  delete[] result;
}
