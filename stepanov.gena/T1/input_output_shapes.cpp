#include "input_output_shapes.hpp"
#include <iomanip>
#include <string>
#include "rectangle.hpp"
#include "circle.hpp"
#include "ellipse.hpp"
#include "square.hpp"

void stepanov::inputRectangle(std::istream& input, Shape** shapes, size_t& size_shapes)
{
  double arguments[4] = {};
  for (int i = 0; i < 4; ++i)
  {
    input >> arguments[i];
    if (!input)
    {
      throw std::invalid_argument("Invalid argument for Rectagle");
    }
  }
  shapes[size_shapes] = new Rectangle({ arguments[0], arguments[1] }, { arguments[2], arguments[3] });
  ++size_shapes;
}


void stepanov::inputCircle(std::istream& input, Shape** shapes, size_t& size_shapes)
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
  shapes[size_shapes] = new Circle({ arguments[0], arguments[1] }, arguments[2]);
  ++size_shapes;
}

void stepanov::inputEllipse(std::istream& input, Shape** shapes, size_t& size_shapes)
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
  shapes[size_shapes] = new Ellipse({ arguments[0], arguments[1] }, arguments[2], arguments[3]);
  ++size_shapes;
}

void stepanov::inputSquare(std::istream& input, Shape** shapes, size_t& size_shapes)
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
  shapes[size_shapes] = new Square({ arguments[0], arguments[1] }, arguments[2]);
  ++size_shapes;
}

void::stepanov::deleteShapes(Shape** shapes, size_t size_shapes)
{
  for (size_t i = 0; i < size_shapes; ++i)
  {
    delete shapes[i];
  }
  delete[] shapes;
}

stepanov::Shape** stepanov::inputShapes(std::istream& input, size_t& size_shapes)
{
  stepanov::Shape** shapes = nullptr;
  shapes = new Shape * [1000] {};
  std::string shape = "";
  while ((input >> shape) && (shape != "SCALE"))
  {
    try
    {
      if (shape == "RECTANGLE")
      {
        inputRectangle(input, shapes, size_shapes);
      }
      else if (shape == "CIRCLE")
      {
        inputCircle(input, shapes, size_shapes);
      }
      else if (shape == "ELLIPSE")
      {
        inputEllipse(input, shapes, size_shapes);
      }
      else if (shape == "SQUARE")
      {
        inputSquare(input, shapes, size_shapes);
      }
    }
    catch (const std::bad_alloc& e)
    {
      stepanov::deleteShapes(shapes, size_shapes);
      throw;
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << "Error: " << e.what() << "\n";
    }
  }
  return shapes;
}

void stepanov::outputShapes(std::ostream& output, const Shape * const * shapes, size_t size_shapes)
{
  if (size_shapes == 0)
  {
    throw std::logic_error("Zero shapes");
  }
  double area = 0.0;
  for (size_t i = 0; i < size_shapes; ++i)
  {
    if (shapes[i])
    {
      area += shapes[i]->getArea();
    }
  }
  output << std::fixed << std::setprecision(1);
  output << area;
  for (size_t i = 0; i < size_shapes; ++i)
  {
    if (shapes[i])
    {
      double width = shapes[i]->getFrameRect().width;
      double height = shapes[i]->getFrameRect().height;
      point_t center = shapes[i]->getFrameRect().center;
      point_t leftCorner = {center.x - width / 2, center.y - height/ 2};
      point_t rightCorner = {center.x + width / 2, center.y + height / 2};
      output << " " << leftCorner.x << " " << leftCorner.y << " " << rightCorner.x << " " << rightCorner.y;
    }
  }
  output << '\n';
}




