#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  int n, k;

  scanf ("%d %d", &n, &k);
  int i, j, l;
  int min, x;
  min = k / 2;
  for (i = 0; i <= k / 5; i++)
    for (j = 0; j <= (k - 5 * i) / 4; j++)
      for (l = 0; l <= (k - 5 * i - 4 * j) / 3; l++)
	{
	  x = n - i - j - l;
	  if (5 * i + 4 * j + 3 * l + 2 * x == k)
	    if (x < min)
	      min = x;
	}
  printf ("%d\n", min);
 return 0;
}
