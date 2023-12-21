#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error in command line argument\n";
    return 1;
  }

  int typeMatrix = 0;
  char* endOfParsing = nullptr;

  try
  {
    typeMatrix = std::strtoll(argv[1], std::addressof(endOfParsing), 10);
  }
  catch (const std::out_of_range&)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 1;
  }
  catch (const std::invalid_argument&)
  {
    std::cerr << "Cannot parse a value\n";
    return 1;
  }

  if (*endOfParsing != '\0')
  {
    std::cerr << "Wrong first argument\n";
    return 1;
  }
}
