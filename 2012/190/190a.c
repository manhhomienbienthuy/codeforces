#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (int argc, char *argv[])
{

  int n, m;
  int min, max;

  scanf ("%d %d", &n, &m);



  if (n == 0)
    {
      if (m > 0)
	printf ("Impossible");
      else 
	printf ("0 0");
    }
  else
    {
      if (n >= m)
	min = n;
      else
	min = m;
      if (m > 0)
	max = n + m - 1;
      else
	max = n;
      printf ("%d %d", min, max);
    }
  return 0;
}
