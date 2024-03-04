#include <iostream>

int main()
{
  size_t capacity = 10;
  char* a = new char[capacity];
  int count = 0;
  while (std::cin >> a[count])
  {
    count++;
  }
  a[count+1] = '\0';
  for (int i = 0; a[i] != '\0'; ++i)
  {
    std::cout << a[i];
  }
  return 0;
}