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

void nikitov::inputArray(CompositeShape& composition, std::string& line, std::istream& input)
{
  bool isErrorInProgram = false;
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
          composition.push_back(insertRectangle(line));
        }
        else if (line.find("DIAMOND") == 0)
        {
          composition.push_back(insertDiamond(line));
        }
        else if (line.find("REGULAR") == 0)
        {
          composition.push_back(insertRegular(line));
        }
      }
      catch (const std::invalid_argument&)
      {
        isErrorInProgram = true;
      }
    }
  }
  catch (...)
  {
    throw;
  }
  if (isErrorInProgram)
  {
    throw std::invalid_argument("Error: Wrong parameters of figure");
  }
}
