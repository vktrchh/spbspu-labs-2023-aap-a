#include <iostream>
#include "input_output_string.hpp"
#include "string.hpp"
#include "strunit.hpp"
#include "replace.hpp"

int main()
{
  using namespace erohin;
  size_t iter_size = 10;
  char* first = nullptr;
  char* first_copy = nullptr;
  char* second = nullptr;
  try
  {
    first = new char[iter_size + 1]{};
    first = inputString(std::cin, first, iter_size);
    if (!length(first))
    {
      delete[] first;
      std::cerr << "String is null\n";
      return 2;
    }
    first_copy = copy(first);
    second = new char[iter_size + 1]{};
    second = inputString(std::cin, second, iter_size);
    first = resize(first, length(first), length(second));
  }
  catch (const std::logic_error&)
  {
    delete[] first;
    delete[] first_copy;
    delete[] second;
    std::cerr << "Wrong string input\n";
    return 2;
  }
  catch (const std::bad_alloc&)
  {
    delete[] first;
    delete[] first_copy;
    delete[] second;
    std::cerr << "Cannot allocate memory\n";
    return 1;
  }
  char old = 'c';
  char change = 'b';
  outputString(std::cout, strunit(first, second));
  std::cout << "\n";
  outputString(std::cout, replace(first_copy, old, change));
  std::cout << "\n";
  delete[] first;
  delete[] first_copy;
  delete[] second;
  return 0;
}
