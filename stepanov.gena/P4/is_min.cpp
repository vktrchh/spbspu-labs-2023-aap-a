#include "is_min.hpp"

bool stepanov::findMin(const int *matrix, size_t index, size_t cols)
{
  size_t i = index;
  size_t c = cols;
  const int *n = matrix + i;
  if ((*n) < *(n - c)
    &&(*n) < *(n + c)
      &&(*n) < *(n - 1)
        &&(*n) < *(n + 1)
          &&(*n) < *(n - c - 1)
            &&(*n) < *(n - c + 1)
              &&(*n) < *(n + c - 1)
                &&(*n) < *(n + c + 1))
  {
    return true;
  }
  else
  {
    return false;
  }
}
