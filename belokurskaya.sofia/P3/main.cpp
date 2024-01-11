#include <iostream>

#include "transform_string.hpp"
#include "reading_a_string.hpp"

int main()
{
  using namespace belokurskaya;
  try
  {
    std::string input_str = inputString(std::cin);
    char * not_input_chars = new char[26]{};

    transformString(input_str.c_str(), nullptr, not_input_chars);

    std::cout << not_input_chars << "\n";

    char* original_input_str = resizeStringBuffer(input_str.c_str(), input_str.size(), input_str.size() + 1);

    toLowerCase(original_input_str);

    std::cout << original_input_str << "\n";

    delete[] not_input_chars;
    delete[] original_input_str;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  return 0;
}
