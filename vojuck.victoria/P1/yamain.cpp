#include "SameMin.hpp"

int main()
{
  using namespace vojuck;
  SequenceCounter counter;
  int number = 0;
  int max_int = std::numeric_limits< int >::max();
  int minElement = max_int;
  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    else if (number != 0)
    {
      try
      {
        counter(number, minElement);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  } while (number != 0);
  std::cout << counter();
}
