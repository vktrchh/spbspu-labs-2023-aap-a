#include <iostream>
#include "createFigure.hpp"
#include <utility>
#include <stdexcept>

int isaychev::checkString(const char * string, const char * strForCheck)
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

size_t isaychev::determineShape(const char * str)
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

size_t isaychev::countWSpaces(const char * str)
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

void isaychev::skipParameter(char * str)
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

void isaychev::parseFigureParams(char * str, const size_t numOfParameters, double * figureParameters)
{
  size_t pos = 0;
  skipParameter(str);
  char * str2 = str;
  for(size_t j = 0; j < numOfParameters; ++j)
  {
    figureParameters[j] = std::stod(str2, &pos);
 //   skipParameter(str);
    str2 += pos;
  }
}

isaychev::Rectangle * isaychev::createRectangle(double * params)
{
  if (params[0] >= params[2] || params[1] >= params[3])
  {
    throw std::logic_error("Incorrect rectangle parameters");
  }
  isaychev::point_t bot = {params[0], params[1]};
  isaychev::point_t top = {params[2], params[3]};
  isaychev::Rectangle * rec = new isaychev::Rectangle(bot, top);
  return rec;
}

isaychev::Shape * isaychev::createFigure(char * str)
{
  size_t numOfCurrFigure = determineShape(str);
  size_t numOfParameters = countWSpaces(str);
  //double * parameters = parseFigureParams(str, numOfParameters);
  isaychev::Shape * currFigure = nullptr;
  if (numOfCurrFigure == 1)
  {
    double parameters[4] = {};
    parseFigureParams(str, numOfParameters, parameters);
    currFigure = createRectangle(parameters);
  }
  else if (numOfCurrFigure == 2)
  {
    double parameters[3] = {};
    parseFigureParams(str, numOfParameters, parameters);
    //currFigure = createCircle(parameters);
  }
  else if (numOfCurrFigure == 3)
  {
    double parameters[4] = {};
    parseFigureParams(str, numOfParameters, parameters);
  //  currFigure = createRegular(parameters);
  }
  return currFigure;
}
