#include <iostream>
#include <iomanip>
#include <cctype>
#include "expand_array.hpp"
#include "define_len.hpp"
#include "exclude_common.hpp"
#include "add_numbers.hpp"

int main()
{
  using namespace lopatina;

  char * input = new char[20]{};
  char c = 0;
  size_t i = 0;
  size_t amount = 20;

  std::cin >> std::noskipws;
  while (std::cin >> c)
  {
    input[i++] = c;
    if (c == '\n')
    {
      input[i - 1] = 0;
      break;
    }
    if (i == (amount - 1))
    {
      try
      {
        char * new_input = expandArray(input, amount);
        delete [] input;
        input = new_input;
        amount += 1;
      }
      catch (const std::bad_alloc & e)
      {
        std::cerr << e.what();
        delete [] input;
        return 1;
      }
    }
  }
  std::cin >> std::skipws;
  if (input[0] == '\0')
  {
    std::cerr << "Empty input\n";
    delete [] input;
    return 1;
  }

  char * result1 = nullptr;
  try
  {
    const char * string1 = "abc";
    const size_t size1 = defineLen(string1);
    char * result1 = excludeCommon(input, string1, amount, size1);
    std::cout << "EXC-SND: " << result1 << '\n';
    delete [] result1;
  }
  catch(std::bad_alloc & e)
  {
    std::cerr << e.what();
    delete [] result1;
    delete [] input;
    return 1;
  }

  char * result2 = 0;
  try
  {
    const char * string2 = "g1h2k";
    const size_t size2 = defineLen(string2);
    char * result2 = addNumbers(input, string2, amount, size2);
    std::cout << "DGT-SND: " << result2 << '\n';
    if (result2 != input)
    {
      delete [] result2;
    }
  }
  catch(std::bad_alloc & e)
  {
    std::cerr << e.what();
    delete [] result2;
    delete [] input;
    return 1;
  }

  delete [] input;
  return 0;
}
