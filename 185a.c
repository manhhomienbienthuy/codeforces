#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define m 1000000007
#define basic 100000
int
main (int argc, char *argv[])
{
  int n;
  unsigned int s = 1;
  unsigned int mul, tmp;

  scanf ("%d", &n);
  mul = 2;
  tmp = 1;
  while (n)
    {
      if (n % 2)
	tmp = (tmp * mul) %  m;
      mul = (mul * mul) % m;
      n /= 2;
    }
  s = ((tmp + tmp * tmp) / 2) % m;
  printf ("%u\n", s);
  return 0;
}
