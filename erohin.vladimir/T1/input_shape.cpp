#include "input_shape.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include "triangle.hpp"
#include "shape.hpp"
#include "create_shape.hpp"

void erohin::inputShape(Shape** result, std::istream& input, size_t& size, point_t& pos, double& ratio)
{
  size = 0;
  bool isFigureCreationFullSuccesful = true;
  bool isScaleCommandEntered = false;
  std::string name;
  double current_par = 0.0;
  const size_t par_max_size = 10;
  size_t par_size = 0;
  double* par = new double[par_max_size]{ 0.0 };
  while (!input.eof() && !isScaleCommandEntered)
  {
    input.clear();
    input >> name;
    while ((input >> current_par) && (par_size != par_max_size))
    {
      par[par_size++] = current_par;
      if (input.peek() == '\n')
      {
        break;
      }
    }
    if (name == "SCALE")
    {
      try
      {
        inputScaleParameteres(par, par_size, pos, ratio);
      }
      catch (const std::logic_error&)
      {
        delete[] par;
        throw;
      }
      isScaleCommandEntered = true;
    }
    else
    {
      try
      {
        Shape* shape_ptr = createShape(name, par, par_size);
        if (shape_ptr)
        {
          result[size++] = shape_ptr;
        }
      }
      catch (const std::invalid_argument&)
      {
        isFigureCreationFullSuccesful = false;
      }
    }
    par_size = 0;
  }
  delete[] par;
  if (!isScaleCommandEntered)
  {
    throw std::logic_error("Scale command do not find");
  }
  else if (!result[0])
  {
    throw std::runtime_error("Nothing to scale");
  }
  else if (!isFigureCreationFullSuccesful)
  {
    throw std::invalid_argument("Wrong figure creation");
  }
}

void erohin::freeShape(Shape** shape, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    delete shape[i];
  }
}
