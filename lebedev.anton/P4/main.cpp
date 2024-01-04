#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error: Four command line arguments are needed\n";
    return 1;
  }

  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Error: First parameter must be 1 or 2\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Error: First parameter must be a number\n";
    return 1;
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "Error: First parameter must be 1 or 2\n";
    return 1;
  }
  return 0;
}
