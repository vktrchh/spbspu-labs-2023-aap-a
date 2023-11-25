#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>


char * transformString(const char * input)
{
  char * result = new char[128];

  for (int i = 0; i < 128; ++i)
  {
    char c = i;
    result[i] = c;

    for (size_t j = 0; j < std::strlen(input); ++j)
    {
      if (input[j] == c)
      {
        result[i] = '\0';
        break;
      }
    }
  }
}


int main()
{
  try
  {
    std::cin >> std::noskipws;

    std::cin >> std::skipws;
    char * result = transformString(input.c_str());

    std::cout << result << "\n";
    delete [] result;
    return 0;
  }

  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory allocation faild\n";
    return 1;
  }
}
