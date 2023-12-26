#include "topclock.h"

void skopchenko::topClock(int *matrix, size_t cols, size_t rows)
{
  int top = 0;
  int bottom = rows - 1;
  int left = 0;
  int right = cols - 1;
  size_t direction = 0; // 0: right, 1: down, 2: left, 3: up
  int value = 1;

  while (top <= bottom && left <= right)
  {
    if (direction == 0)
    {
      for (int i = left; i <= right; ++i)
      {
        matrix[top * cols + i] -= value;
        value++;
      }
      top++;
      direction = 1;
    }
    else if (direction == 1)
    {
      for (int i = top; i <= bottom; ++i)
      {
        matrix[i * cols + right] -= value;
        value++;
      }
      right--;
      direction = 2;
    }
    else if (direction == 2) {
      for (int i = right; i >= left; --i)
      {
        matrix[bottom * cols + i] -= value;
        value++;
      }
      bottom--;
      direction = 3;
    }
    else if (direction == 3)
    {
      for (int i = bottom; i >= top; --i)
      {
        matrix[i * cols + left] -= value;
        value++;
      }
      left++;
      direction = 0;
    }
  }
}
