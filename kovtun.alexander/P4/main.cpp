#include <iostream>
#include <fstream>
#include <exception>

size_t readToArray(std::istream & in, int * array, size_t size, size_t toRead)
{
  size_t min = std::min(toRead, size);
  for (size_t i = 0; i < min; i++)
  {
    if (!(in >> array[i])) {
      return i;
    }
  }

  return min;
}

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

  size_t rows = 0;
  size_t cols = 0;
  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cerr << "file not found\n";
    return 2;
  }

  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "row or/and column number is invalid\n";
    return 2;
  }

  input.close();
}