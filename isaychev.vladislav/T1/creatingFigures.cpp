#include "creatingFigures.hpp"
#include <stdexcept>
#include "stringManipulations.hpp"

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

void isaychev::parseFigureParams(char * str, const size_t numOfParameters, double * figureParameters)
{
  size_t pos = 0;
  skipParameter(str);
  char * str2 = str;
  for(size_t j = 0; j < numOfParameters; ++j)
  {
    figureParameters[j] = std::stod(str2, &pos);
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
