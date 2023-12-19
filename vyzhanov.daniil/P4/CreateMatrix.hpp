#ifndef CREATEMATRIX_HPP
#define CREATEMATRIX_HPP

#include <iostream>
#include <cstddef>

namespace vyzhanov
{
   std::istream &createMatrix(size_t rows, size_t cols, int matrix[], std::istream &inputFile);
}

#endif
