#ifndef DO_TASKS_H
#define DO_TASKS_H

#include <cstddef>
#include <fstream>

namespace skuratov
{
  void doTasks(std::ofstream& out, std::ifstream& in, int* array, size_t cols, size_t rows);
}

#endif
