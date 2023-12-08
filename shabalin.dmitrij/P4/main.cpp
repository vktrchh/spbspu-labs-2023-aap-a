#include <iostream>
#include <fstream> 
#include <cstdlib> 
#include <string> 

int main(int argc, char * argv[]) 
{
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  //argv[1]
  char * task = nullptr;
  int firstArgument = std::strtoll(argv[1], std::addressof(task), 10);
  
  if ((firstArgument > 2) || (firstArgument < 1))
  {
    std::cerr << "Number of task is out of range" << "\n";
    return 2;
  }
  //agrv[2]
  std::fstream input(argv[2]);
  if (!input)
  {
    std::cerr << "Cannot read a number\n";
    return 2;
  }
  //argv[3]
  std::ofstream output(argv[3]);
  if (!output.is_open())
  {
    std::cerr << "Error.Output file is not open" << "\n";
    return 2;
  }
}


