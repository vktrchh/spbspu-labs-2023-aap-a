#include <iostream>
#include <cstring>
#include <cctype>

int hasConsecutiveDuplicates(const char* str)
{
  int length = strlen(str);

  for (int i = 1; i < length; i++)
  {
    if (str[i] == str[i - 1])
    {
      return 1;
    }
  }

  return 0;
}

int main()
{
  const int max_size = 100;
  char str[max_size];

  std::cout << "Enter a string: ";
  std::cin.getline(str, max_size);

  int result = hasConsecutiveDuplicates(str);

  std::cout << "Result: " << result << "\n";

  return 0;
}
