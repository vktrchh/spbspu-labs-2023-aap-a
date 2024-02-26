#ifndef OUTPUT_H
#define OUTPUT_H

#include <cstddef>
#include <fstream>

namespace skopchenko
{

  void output(std::ostream& oFile, const double *matrix, size_t rows, size_t cols);

}

#endif
