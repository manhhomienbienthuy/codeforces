#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (int argc, char * argv[])
{
  int n, a, b, c;
  int max;
  int j, i, k;

  max = 1;
  scanf ("%d %d %d %d", &n, &a, &b, &c);
  int s;

  for (i = 0; i <= n/a; i++)
    for (j = 0; j <= (n - a*i)/b; j++)
      {
	s = n - a*i - b*j;
	if ((s % c) == 0)
	  {
	    k = s/c;
	    if ((i + j + k) > max)
	      max = (i + j + k);
	  }
      }
  printf ("%d", max);
  return 0;
}
