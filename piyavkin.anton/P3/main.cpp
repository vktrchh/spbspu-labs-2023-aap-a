#include <istream>
#include <iostream>
#include "createlinemissinglatinletters.hpp"
#include "inputline.hpp"

int main()
{
  using namespace piyavkin;
  char * new_line = nullptr;
  const size_t number_letters_alphabet = 26;
  char * alphabet = nullptr;
  std::cin >> std::noskipws;
  try
  {
    new_line = inputLine(std::cin);
    alphabet = new char[number_letters_alphabet] {};
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << '\n';
    delete [] new_line;
    return 1;
  }
  std::cin >> std::skipws;
  alphabet = createLineMissingLatinLetters(new_line, alphabet);
  size_t i = 0;
  while (alphabet[i] != '\0')
  {
    std::cout << alphabet[i++];
  }
  std::cout << '\n';
  delete [] new_line;
  delete [] alphabet;
}
