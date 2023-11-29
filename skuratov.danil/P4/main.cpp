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
  }
  else if(argc > 4)
  {
    std::cerr << "Too many arguments" << '\n';
  }

  char* inputFileName = argv[2];
  char* outputFileName = argv[3];

  std::ifstream in(inputFileName);
  std::ofstream out(outputFileName);

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

  return 0;
}
