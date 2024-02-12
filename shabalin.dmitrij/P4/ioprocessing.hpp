#ifndef IOPROCESSING_HPP
#define IOPROCESSING_HPP
#include <cstddef>
#include <iostream>

namespace shabalin
{
  void matrixInput(std::ifstream& input, int* matrix, size_t countOfElements);
  void matrixOutput(std::ofstream& output, const double* matrix, size_t rows, size_t cols);
}

#endif
