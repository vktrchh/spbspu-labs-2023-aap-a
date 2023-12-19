#include <iostream>
#include "input_output_string.hpp"
#include "string.hpp"
#include "strunit.hpp"

int main()
{
  using namespace erohin;
  const size_t iter_size = 10;
  char* first = nullptr;
  char* first_copy = nullptr;
  char* second = nullptr;
  try
  {
    first = new char[iter_size + 1]{};
    first = inputString(std::cin, first, iter_size);
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
    return 1;
  }
  catch (const std::bad_alloc&)
  {
    delete[] first;
    delete[] first_copy;
    delete[] second;
    std::cerr << "Cannot allocate memory\n";
    return 2;
  }
  char old = 0;
  char change = 0;
  std::cin >> std::skipws >> old >> change >> std::noskipws;
  if (!std::cin)
  {
    std::cerr << "Wrong symbols input\n";
    delete[] first;
    delete[] first_copy;
    delete[] second;
    return 1;
  }
  outputString(std::cout, strunit(first, second));
  std::cout << "\n";
  delete[] first;
  delete[] first_copy;
  delete[] second;
  return 0;
}
