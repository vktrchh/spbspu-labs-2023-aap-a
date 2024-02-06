#include "is_min.hpp"

bool stepanov::findMin(const int *matrix, size_t index, size_t cols)
{
  size_t number = matrix[index];
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
