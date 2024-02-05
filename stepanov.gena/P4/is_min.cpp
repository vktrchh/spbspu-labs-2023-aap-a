#include "is_min.hpp"

bool stepanov::isMin(const int *matrix,size_t index, size_t cols)
{
  if (matrix[index] < matrix[index - cols] &&
          matrix[index] < matrix[index + cols] &&
          matrix[index] < matrix[index - 1] &&
          matrix[index] < matrix[index + 1] &&
          matrix[index] < matrix[index - cols - 1] &&
          matrix[index] < matrix[index - cols + 1] &&
          matrix[index] < matrix[index + cols - 1] &&
          matrix[index] < matrix[index + cols + 1])
  {
    return true;
  }
  else
  {
    return false;
  }
}
