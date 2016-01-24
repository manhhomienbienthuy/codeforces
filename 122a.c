#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int
check (int n)
{
  int i, j;
  int x;
  for (i = 1; i <= (int) sqrt (n); i++)
    {
      x = 2 * n - i * (i + 1);
      j = (int) sqrt (x);
      if (j * (j + 1) == x)
	if (j > 0)
	  return 1;
    }
  return 0;		    
}

int
main (int argc, char * argv[])
{
  int n;

  scanf ("%d", &n);
  if (check (n))
    printf ("YES");
  else
    printf ("NO");
  return 0;
}
