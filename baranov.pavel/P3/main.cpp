#include <iostream>

char * inputString(std::istream & input, const size_t bufferSize)
{
  char * buffer = new char[bufferSize]{0};
  char c;
  size_t i = 0;
  while ((input >> c) && (i < bufferSize))
  {
    buffer[i++] = c;
    if (c == '\n')
    {
      buffer[i - 1] = 0;
      break;
    }
  }
  return buffer;
}

int main()
{
  std::cin >> std::noskipws;
  try
  {
    char * buffer = inputString(std::cin, 20);
    std::cout << buffer << '\n';
    delete[] buffer;
  }
  catch(std::bad_alloc & e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  std::cin >> std::skipws;
}

