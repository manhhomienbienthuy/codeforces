#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main (int argc, char *argv[])
{
  int x1, y1, z1;
  int x2, y2, z2;
  double r, dist;

  scanf ("%d %d %d", &x1, &y1, &z1);
  scanf ("%d %d %d", &x2, &y2, &z2);
  dist = sqrt ((x1-x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  if (dist > (z1 + z2))
    r = (dist - (z1 + z2)) / 2;
  else
    {
      if (dist < abs (z1 - z2))
	r = (abs (z1 - z2) - dist) / 2;
      else 
	r = 0;
    }
  printf ("%lf", r);
  return 0;
}
