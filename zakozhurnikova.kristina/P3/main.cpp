#include <iostream>
#include <cstddef>

void removeSpaces(char *dest, const char *src, size_t buff)
{
  size_t index = 0;
  for (size_t  i = 1; i < buff; i++)
  {
    if (src[i - 1] != ' ')
    {
      dest[index] = src[i - 1];
      index++;
    }
    if (src[i] == ' ' && src[i -1] != ' ')
    {
      dest[index] = src[i];
      index++;
    }
  }
}

int main()
{
  size_t size = 20;
  char *buff = nullptr;
  char *string = nullptr;
  char **strPtr = nullptr;
  char c = '\0';
  size_t counter = 0;
  try
  {
    buff = new char[size] {'\0'};
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }

  while (std::cin.get(c))
    {
      if (counter == size - 1)
      {
        size *= 2;
        try
        {
        string = new char[size];
        }
        catch (const std::exception &e)
        {
          std::cerr << e.what() << '\n';
          delete[] buff;
          return 1;
        }
        for (size_t i = 0; i < size/2; i++)
        {
          string[i] = buff[i];
        }
        strPtr = &buff;
        buff = string;
        string = *strPtr;
      }
      buff[counter] = c;
      counter++;
      if(c == '\n')
      {
        std::cout << "End of line\n";
        break;
      }
    }
  char *dest = nullptr;
  for (size_t i = 0; i < size; i++)
  {
    std::cout << buff[i];
  }
  std::cout << '\n';
  try
  {
    dest = new char[size] {'\0'};
  }
  catch (const std::exception  &e)
  {
    std::cerr << e.what() << '\n';
    delete[] string;
    delete[] buff;
    return 1;
  }
  removeSpaces(dest, buff, size);
  return 0;
}
