#include <stdio.h>
#include <stdlib.h>

unsigned int
ucln (unsigned int a, unsigned int b)
{
  unsigned int r;
  while (b != 0)
    {
      r = a % b;
      a = b;
      b = r;
    }
  return a;
}

unsigned int
bcnn (unsigned int a, unsigned int b)
{
  return b / ucln (a, b);
}

int
main (int argc, char * argv[])
{
  int t;
  int a[10000];
  int i;

  scanf ("%d", &t);
  for (i = 0; i < t; i++)
    scanf ("%d", &a[i]);

  unsigned int s, x, pr;

  for (i = 0; i < t; i++)
    {
      s = a[i] + 1;
      x = 4 * a[i];
      pr = bcnn (s, x);
      pr = pr + 1;
      printf ("%u \n",pr);
    }
  return 0;
}
