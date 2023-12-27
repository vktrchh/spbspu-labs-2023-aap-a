#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

void isoScale(Shape * shape, point_t center, double k)
{
  if (k < 0)
  {
    throw std::logic_error("Сoefficient less than 0");
  }
  point_t pos = shape->getFrameRect().pos;
  shape->move(center);
  shape->scale(k);
  shape->move(k * (pos.x - shape->getFrameRect().pos.x), k * (pos.y - shape->getFrameRect().pos.y));
}

int main()
{
    try {
        point_t lny = { 0,0 };
        point_t pvy = { 2,2 };
        Rectangle r1(pvy, lny);
        std::cout << r1.getArea() << "\n";
        std::cout << r1.getFrameRect().heigth << "\n";
        std::cout << r1.getFrameRect().width << "\n";
        std::cout << r1.getFrameRect().pos.x << " ";
        std::cout << r1.getFrameRect().pos.y << "\n";
        r1.move({ 3,3 });
        r1.scale(5);
        std::cout << r1.getFrameRect().heigth << "\n";
        std::cout << r1.getFrameRect().width << "\n";
        std::cout << r1.getFrameRect().pos.x << " ";
        std::cout << r1.getFrameRect().pos.y << "\n" << r1.getArea() << "\n" << "\n";
        Triangle tr1(lny, pvy, { 4,0 });
        std::cout << tr1.getArea() << "\n";
        std::cout << tr1.getFrameRect().heigth << "\n";
        std::cout << tr1.getFrameRect().width << "\n";
        std::cout << tr1.getFrameRect().pos.x << " ";
        std::cout << tr1.getFrameRect().pos.y << "\n";
        tr1.move(3, 5);
        tr1.scale(5);
        std::cout << tr1.getFrameRect().heigth << "\n";
        std::cout << tr1.getFrameRect().width << "\n";
        std::cout << tr1.getFrameRect().pos.x << " ";
        std::cout << tr1.getFrameRect().pos.y << "\n" << tr1.getArea() << "\n";
    }
    catch (const std::logic_error& e)
    {
        std::cerr << e.what() << "\n";
        return 1;
    }
}
