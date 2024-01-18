#include "increasearray.hp
namespace gladyshev
{
  void increaseArray(double * arr, size_t& counter, rectangle_t frame)
  {
    for (size_t i = 0; i < 2; ++i)
    {
      arr[counter++] = (i % 2 == 0) ? frame.pos.x - frame.width / 2 : frame.pos.x + frame.width / 2;
      arr[counter++] = (i % 2 == 0) ? frame.pos.y - frame.height / 2 : frame.pos.y + frame.height / 2;
    }
  }
}
