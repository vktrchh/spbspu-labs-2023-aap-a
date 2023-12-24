#include <iostream>


int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    if (argc < 4)
    {
      std::cerr << "Not enough arguments\n";
    }
    else if (argc > 4)
    {
      std::cerr << "Too many arguments\n";
    }

    return 1;
  }
}