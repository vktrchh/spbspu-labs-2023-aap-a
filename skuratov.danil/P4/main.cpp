#include <iostream>
#include <fstream>
#include <cctype>

int main(int argc, char* argv[])
{
  if (argc < 4)
  {
    std::cerr << "Not enough parameters" << '\n';
  }
  else if(argc > 4)
  {
    std::cerr << "Too many arguments" << '\n';
  }
  int taskNumber = std::atoi(argv[1]);
  if (taskNumber == 1)
  {
  
  }
  else if (taskNumber == 2)
  {
  
  }
  else
  {
  	std::cerr << "The first parameter is out of range" << '\n';
  }
  char* inputFileName = argv[2];
  std::ifstream in(inputFileName);
  if (!in)
  {
  	std::cerr << "Invalid input file" << '\n';
  }
  return 0;
}
