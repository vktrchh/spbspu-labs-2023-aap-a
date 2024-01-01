#include <iostream>
#include <string>
#include "shape.hpp"
//#include "rectangle.hpp"
//#include "base-types.hpp"
#include "inputString.hpp"
int checkString(const char * string, const char * strForCheck)
{
  size_t i = 0;
  int checkFlag = 1;
  while (strForCheck[i] != '\0')// || string[i] != '\0')
  {
    if (strForCheck[i] != string[i])
    {
      checkFlag = 0;
    }
    i++;
  }
  return checkFlag;
}

size_t determineShape(const char * str)
{
  constexpr size_t numOfFigures = 3;
  const char * figureNames[numOfFigures] = {"RECTANGLE", "CIRCLE", "REGULAR"};
  size_t numOfCurrFigure = 1;
  for (size_t i = 0; i < numOfFigures; i++)
  {
    if (checkString(str, figureNames[i]) == 1)
    {
      return numOfCurrFigure;
    }
    numOfCurrFigure++;
  }
  return 0;
}

//  size_t countWSpaces(const char * str) {}

  //double * parseFigureDesc

/*Shape * createFigure(const char * str)
{
  numOfCurrFigure = determineShape(str);
  Shape * currFigure = nullptr;
  if (numOfCurrFigure == 0)
  {
    std::cout << "null\n";
    return currFigure;
  }
  else if (numOfCurrFigure == 1)
  {
//    currFigure = createRectangle();
    std::cout << "rec\n";
    return currFigure;
  }
  else if (numOfCurrFigure == 2)
  {
    currFigure = createCircle();
    return currFigure;
  }
  else if (numOfCurrFigure == 3)
  {
    currFigure = createRegular();
    return currFigure;
  }
}*/

int main()
{
  using namespace isaychev;
  const char * scaleStr = "SCALE ";
  char * currDesc = nullptr;
  size_t capacity = 10, length = 0, i = 0;
  Shape * Figures[1000] = {};
  while (std::cin)
  {
    try
    {
    currDesc = inputString(std::cin, length, capacity);
    }
    catch(const char * errMessage)
    {
      std::cerr << errMessage << "\n";
      return 1;
    }
    std::cout << currDesc << "\n";
    if (checkString(currDesc, scaleStr) == 1)
    {
      break;
    }
    std::cout << determineShape(currDesc) << "\n";
    delete [] currDesc;
  }
  delete [] currDesc;
}
