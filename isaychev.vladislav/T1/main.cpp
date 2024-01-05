#include <iostream>
#include <string>
#include <utility>
#include "shape.hpp"
#include "rectangle.hpp"
#include "inputString.hpp"

int checkString(const char * string, const char * strForCheck)
{
  size_t i = 0;
  int checkFlag = 1;
  while (strForCheck[i] != '\0')
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

size_t countWSpaces(const char * str)
{
  size_t counter = 0, i = 0;
  while (str[i] != '\0')
  {
    if (str[i] == ' ')
    {
      counter++;
    }
    i++;
  }
  return counter;
}

void skipParameter(char * str)
{
  size_t i = 0;
  while (str[i] != ' ')
  {
    i++;
  }
  for (size_t j = 0; j < i + 1; j++)
  {
    size_t k = 0;
    while (str[k + 1] != '\0')
    {
      std::swap(str[k], str[k + 1]);
      k++;
    }
    str[k] = '\0';
  }
}

double * parseFigureParams(char * str, size_t numOfParameters)
{
  double * figureParameters = nullptr;
  figureParameters = new double[numOfParameters]{};
  if (figureParameters == nullptr)
  {
    return figureParameters;
  }
  skipParameter(str);
  for(size_t j = 0; j < numOfParameters; ++j)
  {
    figureParameters[j] = std::stod(str, nullptr);//getFirstParam(str);
    skipParameter(str);
  }
  return figureParameters;
}

isaychev::Rectangle * createRectangle(double * params)
{
  if (params[0] >= params[2] || params[1] >= params[3])
  {
    throw std::logic_error("Incorrect rectangle parameters");
  }
  isaychev::point_t bot = {params[0], params[1]};
  isaychev::point_t top = {params[2], params[3]};
  isaychev::Rectangle * rec = nullptr;
  rec = new isaychev::Rectangle(bot, top);
  return rec;
}

isaychev::Shape * createFigure(char * str)
{
  size_t numOfCurrFigure = determineShape(str);
  size_t numOfParameters = countWSpaces(str);
  double * parameters = parseFigureParams(str, numOfParameters);
  isaychev::Shape * currFigure = nullptr;
  if (numOfCurrFigure == 1)
  {
    currFigure = createRectangle(parameters);
    return currFigure;
  }
  else if (numOfCurrFigure == 2)
  {
//    currFigure = createCircle(parameters);
    return currFigure;
  }
  else if (numOfCurrFigure == 3)
  {
  //  currFigure = createRegular(parameters);
    return currFigure;
  }
  return currFigure;
}

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
    if (checkString(currDesc, scaleStr) == 1)
    {
      break;
    }
//    Figures[i] = createFigure(currDesc);
    delete [] currDesc;
  }
  delete [] currDesc;
}
