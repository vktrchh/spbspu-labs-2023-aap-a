#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace stepanov
{
  class point_t
  {
  private:
    double x;
    double y;
  };

  class rectangle_t
  {
  private:
    double width;
    double height;
    point_t pos;
  };
}
#endif
