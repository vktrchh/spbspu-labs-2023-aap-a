#ifndef OUTPUT_H
#define OUTPUT_H

#include <cstddef>
#include <fstream>

namespace skopchenko
{

  void intOutput(std::ostream& oFile, int *matrix, size_t rows, size_t cols);

  void doubleOutput(std::ostream& oFile, const double *matrix, size_t rows, size_t cols);

}

#endif
