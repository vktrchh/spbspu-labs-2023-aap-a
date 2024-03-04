#include <iostream>

int main()
{
  size_t capacity = 10;
  char* a = new char[capacity];
  size_t size = 0;

  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char* new_str = new char[capacity + 20];
        for (auto i =a, j = new_str; i != a + size; ++i, ++j)
        {
          *j = *i;
        }
        delete[] a;
        a = new_str;
        capacity += 20;
      }
      catch (const std::bad_alloc& e)
      {
        delete[] a;
        throw e;
      }
    }
    std::cin >>a[size];
  }
  while (std::cin && a[size++] != '\n');

  a[size - 1] = '\0';
  for (int i = 0; a[i] != '\0'; ++i)
  {
    std::cout << a[i];
  }
  return 0;
}