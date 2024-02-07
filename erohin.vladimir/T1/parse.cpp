#include "parse.hpp"
#include <stdexcept>
#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
#include "complexquad.hpp"

erohin::Shape* erohin::parseShape(const std::string string, point_t& pos, double& ratio)
{
  const size_t par_max_size = 10;
  double* par = nullptr;
  try
  {
    par = new double[par_max_size]{ 0.0 };
    size_t par_number = 0;
    std::string str = "";
    std::string name = "";
    bool isFigureNameFull = false;
    for (size_t i = 0; i <= string.length(); ++i)
    {
      if (i < string.length() && string[i] != ' ')
      {
        str += string[i];
      }
      else if (isFigureNameFull && par_number < par_max_size)
      {
        par[par_number++] = stod(str, nullptr);
        str = "";
      }
      else
      {
        name = str;
        str = "";
        isFigureNameFull = true;
      }
    }
    erohin::Shape* shape = createShape(name, par, par_number, pos, ratio);
    delete[] par;
    return shape;
  }
  catch (...)
  {
    delete[] par;
    throw;
  }
}

erohin::Shape* erohin::createShape(const std::string name, double* par, size_t par_size, point_t& pos, double& ratio)
{
  Shape* shape = nullptr;
  if (name == "RECTANGLE")
  {
    shape = createRectangle(par, par_size);
  }
  else if (name == "TRIANGLE")
  {
    shape = createTriangle(par, par_size);
  }
  else if (name == "DIAMOND")
  {
    shape = createDiamond(par, par_size);
  }
  else if (name == "COMPLEXQUAD")
  {
    shape = createComplexquad(par, par_size);
  }
  else if (name == "SCALE")
  {
    inputScaleParameteres(par, par_size, pos, ratio);
  }
  return shape;
}

erohin::Shape* erohin::createRectangle(double* par, size_t par_size)
{
  if (par_size == 4)
  {
    Shape* shape = new Rectangle({ par[0], par[1] }, { par[2], par[3] });
    return shape;
  }
  else
  {
    throw std::invalid_argument("Wrong figure parameteres number");
  }
}

erohin::Shape* erohin::createTriangle(double* par, size_t par_size)
{
  if (par_size == 6)
  {
    point_t point[3];
    for (int i = 0; i < 3; ++i)
    {
      point[i] = { par[2 * i], par[2 * i + 1] };
    }
    Shape* shape = new Triangle(point);
    return shape;
  }
  else
  {
    throw std::invalid_argument("Wrong figure parameteres number");
  }
}

erohin::Shape* erohin::createComplexquad(double* par, size_t par_size)
{
  if (par_size == 8)
  {
    point_t point[4];
    for (int i = 0; i < 4; ++i)
    {
      point[i] = { par[2 * i], par[2 * i + 1] };
    }
    Shape* shape = new Complexquad(point);
    return shape;
  }
  else
  {
    throw std::invalid_argument("Wrong figure parameteres number");
  }
}

erohin::Shape* erohin::createDiamond(double* par, size_t par_size)
{
  if (par_size == 6)
  {
    point_t point[3];
    for (int i = 0; i < 3; ++i)
    {
      point[i] = { par[2 * i], par[2 * i + 1] };
    }
    Shape* shape = new Diamond(point);
    return shape;
  }
  else
  {
    throw std::invalid_argument("Wrong figure parameteres number");
  }
}

void erohin::inputScaleParameteres(double* par, size_t par_size, point_t& pos, double& ratio)
{
  if (par_size == 3 && par[2] > 0.0)
  {
    pos = { par[0], par[1] };
    ratio = par[2];
  }
  else
  {
    throw std::logic_error("Wrong scale comand parameteres");
  }
}
