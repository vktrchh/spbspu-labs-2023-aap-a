#include <iostream>

const int min_int = std::numlic_limits< int >::max();
int main()
{
  int num = 0;
  size_t lenght = 0;
  int max_element = min_int;
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
