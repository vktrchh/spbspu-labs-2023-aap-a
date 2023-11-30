#include <iostream>
#include <fstream>
#include <cctype>
#include <cstddef>

int main(int argc, char* argv[])
{
  const size_t MAX_SIZE = 10000;

  if (argc < 4)
  {
    std::cerr << "Not enough parameters" << '\n';
    return 1;
  }
  else if(argc > 4)
  {
    std::cerr << "Too many arguments" << '\n';
    return 1;
  }

  char* inputFileName = argv[2];
  char* outputFileName = argv[3];
  int taskNumber = std::atoi(argv[1]);

  std::ifstream in(inputFileName);
  std::ofstream out(outputFileName);

  try
  {

  }
  catch (const std::runtime_error& error)
  {
    std::cerr << error.what() << '\n';
    return 2;
  }

  try
  {

  }
  catch (const std::runtime_error& error)
  {
    std::cerr << error.what() << '\n';
    return 2;
  }

  if (taskNumber == 1)
  {
    
  }
  else if (taskNumber == 2)
  {
    
  }
  else
  {
  	std::cerr << "Invalid first parameter" << '\n';
    return 1;
  }

  return 0;
}
