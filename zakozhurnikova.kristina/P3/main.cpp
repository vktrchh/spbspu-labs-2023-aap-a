#include <iostream>


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
