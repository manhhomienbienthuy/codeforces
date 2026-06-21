#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main (int argc, char *argv[])
{
  int a, b, r;
  int result;

  scanf ("%d %d %d", &a, &b, &r);
  double x = r * (2 + sqrt (3));

  if (2 * r <= a && 2 * r <= b)
    printf ("First\n");
  else
    printf ("Second\n");
  return 0;
}
