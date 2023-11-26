#include <iostream>
#include <cstddef>

void removeSpaces(char *dest, const char *src, size_t buff)
{
  size_t index = 0;
  for (size_t  i = 1; i < buff; i++)
  {
    if (src[i] == '\0')
    {
      break;
    }
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
  if (dest[index - 1] == ' ')
  {
    dest[index - 1] = '\0';
  }
}

int main()
{
  size_t size = 20;
  char *buff = nullptr;
  char *string = nullptr;
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
        try
        {
          string = new char[size] {'\0'};
        }
        catch (const std::exception &e)
        {
          std::cerr << e.what() << '\n';
          delete[] buff;
          buff = nullptr;
          return 1;
        }
        size *= 2;
        delete[] buff;
        buff = nullptr;
        try
        {
          buff = new char[size] {'\0'};
        }
        catch (const std::exception &e)
        {
          std::cerr << e.what() << '\n';
          delete[] string;
          string = nullptr;
          return 1;
        }
        for (size_t i = 0; i < size/2; i++)
        {
          buff[i] = string[i];
        }
        delete[] string;
        string = nullptr;
      }
      buff[counter] = c;
      counter++;
      if(c == '\n')
      {
        break;
      }
    }
  char *tmp = nullptr;
  try
  {
    tmp = new char[size] {'\0'};
  }
  catch (const std::exception  &e)
  {
    std::cerr << e.what() << '\n';
    delete[] string;
    delete[] buff;
    return 1;
  }
  removeSpaces(tmp, buff, size);
  char *head = tmp;
  while (*head)
  {
    std::cout << *head;
    head++;
  }
  std::cout << '\n';
  head = nullptr;
  delete[] tmp;
  delete[] buff;
  buff = nullptr;
  tmp = nullptr;
  return 0;
}
