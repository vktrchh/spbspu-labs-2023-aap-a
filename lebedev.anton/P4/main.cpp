#include <iostream>
#include <fstream>
#include <string>
#include "input_array.hpp"

int main(int argc, char * argv[])
{
  using namespace lebedev;

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

  size_t rows = 0;
  size_t cols = 0;
  {
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Error: Cannot read a number of rows or cols\n";
      return 2;
    }
  }

  size_t nzr_dig_counter = 0;
  //long long min_sum_sdg = std::numeric_limits< long long >::max();
  int static_array[10000] = {};
  int * array = nullptr;
  if (num == 1)
  {
    array = static_array;
  }
  if (num == 2)
  {
    try
    {
      array = new int[rows * cols];
    }
    catch (const std::bad_alloc &)
    {
      std::cerr << "Error: Cannot allocate memory\n";
      return 3;
    }
  }

  return 0;
}
