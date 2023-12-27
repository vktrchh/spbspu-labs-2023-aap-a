#include "topclock.h"

void skopchenko::topClock(int *matrix, size_t rows, size_t cols, size_t value, size_t top, size_t bottom, size_t left, size_t right)
{
  if (top > bottom || left > right) {
    return;
  }

  for (size_t i = left; i <= right; ++i) {
    matrix[top * cols + i] -= value;
    value++;
  }
  top++;

  for (size_t i = top; i <= bottom; ++i) {
    matrix[i * cols + right] -= value;
    value++;
  }
  right--;

  if (top <= bottom) {
    for (size_t i = right; i + 1 >= left + 1; --i) {
      matrix[bottom * cols + i] -= value;
      value++;
    }
    bottom--;
  }

  if (left <= right) {
    for (size_t i = bottom; i + 1 >= top + 1; --i) {
      matrix[i * cols + left] -= value;
      value++;
    }
    left++;
  }
  skopchenko::topClock(matrix, rows, cols, value, top, bottom, left, right);
}
