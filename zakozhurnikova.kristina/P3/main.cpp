#include <iostream>
#include <cstddef>
#include <fstream>

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
  }

int main()
{
  size_t size = 20;
  char *buff = new char[size]{};
  char *string = nullptr;
  char **strPtr = nullptr;
  char c = '\0';
  while (std::cin.get(c))
    {
      if (counter == size - 1)
      {
        size *= 2;
        string = new char[size];
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
  char *dest = new char[size];
  removeSpaces(dest, buff, size);
  std::ofstream out("output");
  out << dest;
  return 0;
}
