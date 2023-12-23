#include "cpline.hpp"
#include <istream>
#include "createalphabet.hpp"
#include "createline.hpp"
#include "inputline.hpp"
#include <iostream>

int main()
{
  using namespace piyavkin;
  size_t length = 0;
  char * new_line = nullptr;
  std::cin >> std::noskipws;
  try
  {
    new_line = inputLine(std::cin, length);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what();
    return 1;
  }
  std::cin >> std::skipws;
  bool alphabet [26] = {};
  size_t count = createAlphabet(alphabet, new_line, length);
  delete [] new_line;
  char * new_alphabet = nullptr;
  try
  {
    new_alphabet = new char [count+1];
  }
  catch (...)
  {
    std::cerr << "Dynamic memory overflow\n";
    return 1;
  }
  new_alphabet[count] = '\0';
  createLine(alphabet, new_alphabet);
  for (size_t i = 0; i < count+1; ++i)
  {
    std::cout << new_alphabet[i];
  }
  std::cout << '\n';
  delete [] new_alphabet;
}
