#include "topclock.h"

void skopchenko::topClock(int *matrix, size_t rows, size_t cols, size_t value, int top, size_t bottom, int left, size_t right)
{
  if (top > bottom || left > right) {
    return;
  }

  for (int i = left; i <= right; ++i) {
    matrix[top * cols + i] -= value;
    value++;
  }
  top++;

  for (int i = top; i <= bottom; ++i) {
    matrix[i * cols + right] -= value;
    value++;
  }
  right--;

  if (top <= bottom) {
    for (int i = right; i >= left; --i) {
      matrix[bottom * cols + i] -= value;
      value++;
    }
    bottom--;
  }

  if (left <= right) {
    for (int i = bottom; i >= top; --i) {
      matrix[i * cols + left] -= value;
      value++;
    }
    left++;
  }
  skopchenko::topClock(matrix, rows, cols, value, top, bottom, left, right);
}
