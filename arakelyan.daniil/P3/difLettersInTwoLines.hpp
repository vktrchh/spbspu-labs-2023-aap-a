#ifndef DIFLETTERSINTWOLINES_HPP
#define DIFLETTERSINTWOLINES_HPP
#include <cstddef>
namespace arakelyan
{
  void searchForDifferentLettersInTwoLines(const char *inputArr, const char *defaultArray, char *answer);
  void findAndInsertDiffLetters(const char *array, char *answer, size_t &freePos);
}
#endif
