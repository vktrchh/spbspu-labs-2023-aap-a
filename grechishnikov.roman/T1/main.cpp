#include "rectangle.hpp"
#include <stdexcept>
#include <iostream>
int main()
{
  using namespace grechishnikov;
  point_t l {1.0, 1.0}, r {5.0, 5.0};
  Rectangle re(l, r);
  rectangle_t t = re.getFrameRect();
  std::cout << t.width << " " << t.height << " " << t.pos.x << " " << t.pos.y << "\n";
  re.scale(2.0);
  rectangle_t t2 = re.getFrameRect();
  std::cout << t2.width << " " << t2.height << " " << t2.pos.x << " " << t2.pos.y << "\n";
}
