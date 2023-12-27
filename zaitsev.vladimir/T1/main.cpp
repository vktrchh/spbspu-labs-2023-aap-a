#include <iostream>
#include "base-types.h"
#include "Geom_fuctions.h"

int main()
{
  using namespace zaitsev;
  using namespace std;
  point_t p[4];

  cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y >> p[3].x >> p[3].y;

  if (checkIntersection(p))
  {
    point_t p1= findIntersection(p);
    cout << p1.x <<" "<< p1.y;
  }
  return 0;
}
