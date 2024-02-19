#include "input_output_shapes.hpp"
#include <string>
#include "rectangle.hpp"
#include "circle.hpp"
#include "ellipse.hpp"
#include "square.hpp"

void stepanov::inputRectangle(std::istream& input, Shape ** shapes, size_t size_shapes)
{
  double arguments[4] = {};
  for (int i = 0; i < 4,; ++i)
  {
    input >> arguments[i];
    if (!input)
    {
      throw std::invalid_argument("Invalid argument for Rectagle");
    }
  }
  shapes[size_shapes] = new Rectangle({arguments[0], arguments[1], arguments[2], arguments[3]});
  ++size_shapes;
}

void stepanov::inputCircle(std::istream& input, Shape ** shapes, size_t size_shapes)
{
  double arguments[3] = {};
  for (int i = 0; i < 3; ++i)
  {
    input >> arguments[i];
    if (!input)
    {
      throw std::invalid_argument("Invalid argument for Circle");
    }
  }
  shapes[size_shapes] = new Circle({arguments[0], arguments[1], arguments[2]});
  ++size_shapes;
}

void stepanov::inputEllipse(std::istream& input, Shape ** shapes, size_t size_shapes)
{
  double arguments[4] = {};
  for (int i = 0; i < 4; ++i)
  {
    input >> arguments[i];
    if (!input)
    {
      throw std::invalid_argument("Invalid argument for Ellipse");
    }
  }
  shapes[size_shapes] = new Ellipse({arguments[0], arguments[1], arguments[2], arguments[3]});
  ++size_shapes;
}

void stepanov::inputSquare(std::istream& input, Shape ** shapes, size_t size_shapes)
{
  double arguments[3] = {};
  for (int i = 0; i < 3; ++i)
  {
    input >> arguments[i];
    if (!input)
    {
      throw std::invalid_argument("Invalid argument for Square");
    }
  }
  shapes[size_shapes] = new Rectangle({arguments[0], arguments[1], arguments[2]});
  ++size_shapes;
}

void::stepanov::deleteShapes(Shape ** shapes, size_t size_shapes)
{
  for (size_t i = 0; i < size_shapes; ++i)
  {
    delete shapes[i];
  }
  delete[] shapes;
}

stepanov::Shape ** stepanov::inputShapes(std::istream& input, size_t& size_shapes)
{
  stepanov::Shape ** shapes = nullptr;
  std::string shape = "";
  while ((input >> shape) && (shape != "SCALE"))
  {
    try
    {
      if (shape == "RECTANGLE")
      {
        inputRectangle();
      }
      else if (shape == "CIRCLE")
      {
        inputCircle();
      }
      else if (shape == "ELLIPSE")
      {
        inputEllipse();
      }
      else if (shape == "SQUARE")
      {
        inputSquare();
      }
    }
    catch (const std::bad_alloc& e)
    {
      stepanov::deleteShapes();
      std::cerr << "Error: " << e.what() << "\n";
      return 1;
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << "Error: " << e.what() << "\n";
    }
  }
}










