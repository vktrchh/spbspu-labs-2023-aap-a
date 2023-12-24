#include <iostream>
#include <fstream>
#include <exception>


int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    if (argc < 4)
    {
      std::cerr << "not enough arguments\n";
    }
    else
    {
      std::cerr << "too many arguments\n";
    }

    return 1;
  }

  size_t num = 0;
  try
  {
    num = std::stoll(argv[1]);
    if (num != 1 && num != 2)
    {
      std::cerr << "the task number must be 1 or 2\n";
      return 1;
    }
  }
  catch (const std::exception & e)
  {
    std::cerr << "failed to parse the task number: " << e.what() << "\n";
    return 1;
  }

  
}