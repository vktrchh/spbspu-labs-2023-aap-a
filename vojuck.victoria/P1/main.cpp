#include <iostream>

int main()
{
  int num = 0;
  size_t lenght = 0;
  int maxElement = 0;
  do
  {
    std::cin >> num;
    if(!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    else if (num != 0)
    {
      if (maxElement < num)
      {
        lenght = 0;
        maxElement = num;
      }
      else
      {
       ++ lenght;
      }
    }
  }
  while (num !=0);
  std::cout << lenght  << "\n";
}