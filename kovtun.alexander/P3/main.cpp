#include <iostream>
#include <iomanip>

int main()
{
  size_t stringSize = 5;
  size_t charIndex = 0;
  char c = '\n';
  char * input = new char[stringSize]();

  std::cin >> std::noskipws;
  while (std::cin >> c  && charIndex < stringSize)
  {
    if (c == '\n')
    {
      input[charIndex] = '\0';
      break;
    }

    input[charIndex] = c;
    charIndex++;
  }
  std::cin >> std::skipws;

  std::cout << input;
  delete [] input;

  return 0;
}
