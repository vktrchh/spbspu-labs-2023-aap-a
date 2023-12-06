#ifndef READ_ARRAY_H
#define READ_ARRAY_H

#include <fstream>
#include <cstddef>

int* readArray(std::ifstream& in, int array[], const size_t& rows, const size_t& cols);
#endif
