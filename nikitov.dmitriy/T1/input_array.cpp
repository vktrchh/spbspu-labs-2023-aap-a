#include "input_array.hpp"
#include <iostream>
#include <string>
#include <limits>
#include "shape.hpp"
#include "insert_figures.hpp"

void nikitov::recognizeScaleParameters(std::string line, point_t& isoScaleCenter, double& ratio)
{
  std::string name = "SCALE";
  line = line.substr(name.length());
  const char* cLine = line.c_str();
  size_t coordinatePointer = 0;
  double coordinates[3] = {};
  for (size_t i = 0; i != 3; ++i)
  {
    coordinates[i] = std::stod(cLine, std::addressof(coordinatePointer));
    cLine += coordinatePointer;
  }
  isoScaleCenter = { coordinates[0], coordinates[1] };
  ratio = coordinates[2];
}

nikitov::Shape** increaseArray(nikitov::Shape** figures, size_t nFigures)
{
  nikitov::Shape** newFigures = new nikitov::Shape*[nFigures + 1]{ nullptr };
  for (size_t i = 0; i != nFigures; ++i)
  {
    newFigures[i] = figures[i];
  }
  return newFigures;
}

void nikitov::freeArray(Shape** figures, size_t nFigures)
{
  for (size_t i = 0; i != nFigures; ++i)
  {
    delete figures[i];
  }
  delete[] figures;
}

nikitov::Shape** nikitov::inputArray(std::string& line, size_t& nFigures, bool& isErrorInProgram, std::istream& input)
{
  Shape** figures = new Shape*[1]{ nullptr };
  try
  {
    while (input && line.find("SCALE") != 0)
    {
      std::getline(input, line);
      if (!input)
      {
        throw std::logic_error("Error: Wrong input");
      }

      try
      {
        if (line.find("RECTANGLE") == 0)
        {
          figures[nFigures] = insertRectangle(line);
        }
        else if (line.find("DIAMOND") == 0)
        {
          figures[nFigures] = insertDiamond(line);
        }
        else if (line.find("REGULAR") == 0)
        {
          figures[nFigures] = insertRegular(line);
        }
      }
      catch (const std::invalid_argument&)
      {
        isErrorInProgram = true;
      }

      if (figures[nFigures] != nullptr)
      {
        ++nFigures;
        Shape** tempFigures = increaseArray(figures, nFigures);
        delete[] figures;
        figures = tempFigures;
      }
    }
  }
  catch (...)
  {
    freeArray(figures, nFigures);
    throw;
  }
  return figures;
}
