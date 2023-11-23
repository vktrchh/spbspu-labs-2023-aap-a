#include <iostream>
#include <stdexcept>
#include "stringInput.hpp"
#include "twoStrings.hpp"


int main()
{
  char * firstStr = nullptr;
  char * secondStr = nullptr;
  using namespace rebdev;

  try
  {
    firstStr = inputStr(std::cin);
    secondStr = inputStr(std::cin);
    if ((firstStr == nullptr) || (secondStr == nullptr))
    {
      throw std::logic_error("Error message");
    }
  }
  catch (std::logic_error & e)
  {
    delete[] firstStr;
    delete[] secondStr;
    return 1;
  }

  char * rez = stringConversion(firstStr, secondStr);
  std::cout << rez << '\n';
  delete[] rez;
  delete[] firstStr;
  delete[] secondStr;
  return 0;
}

/*[DGT-SND] Сформировать новую строку из двух исходных, добавив в первую все символы, встреча-ющиеся во второй и являющиеся десятичными цифрами
abc_def //Expects output (return 0) with second string "g1h2k": abc_def12
*/
