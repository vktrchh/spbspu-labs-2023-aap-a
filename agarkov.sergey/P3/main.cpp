#include <iostream>

int main()
{
  char a[100];
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