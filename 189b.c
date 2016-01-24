#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main (int argc, char *argv[])
{
  int w, h;
  int a, b, suba, subb, xa, xb;
  unsigned int max;

  scanf ("%d %d", &w, &h);

  max = 0;
  suba = 1;  
  for (a = 1; a <= w/2; a++)
    {
      xa = w - suba;
      subb = 1;
      for (b = 1; b <= h/2; b++);
      {
	xb = h - subb;
	max += xa * xb;
	printf ("max = %d\n", max);
	subb += 2;
      }
      suba += 2;
    }

  printf ("%u\n", max);
 
  return 0;
}
