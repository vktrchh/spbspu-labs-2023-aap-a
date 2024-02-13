#include <iostream>
#include <iomanip>

int main()
{
  size_t stringSize = 50;
  size_t charIndex = 0;
  char c = '\n';
  char * input = new char[stringSize]();

  std::cin >> std::noskipws;
  while (std::cin >> c)
  {
    if (c == '\n')
    {
      input[charIndex] = '\0';
      break;
    }

    input[charIndex] = c;
    charIndex++;

    if (charIndex == stringSize)
    {
      // possible wrapping around
      stringSize *= 2;
      char * copy = new char[stringSize]();
      // TODO: handle bad allocation
      for (int i = 0; i < charIndex; i++)
      {
        copy[i] = input[i];
      }
      delete [] input;
      input = copy;
    }
  }
  std::cin >> std::skipws;

  std::cout << input << '\n';
  delete [] input;

  return 0;
}
