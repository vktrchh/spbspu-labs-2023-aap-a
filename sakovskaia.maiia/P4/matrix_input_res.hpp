#ifndef MATRIX_INPUT_ANS_HPP
#define MATRIX_INPUT_ANS_HPP
#include <cstddef>
#include <fstream>

namespace sakovskaia
{
  std::ostream & printAnswer(std::ostream & output, const int * a, size_t b);
  void AnswerCounter(int * input_matrix, int * counterclockwise_matrix, size_t size);
}
#endif
