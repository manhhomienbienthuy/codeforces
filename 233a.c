#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char * argv[])
{
  int n, i;

  scanf ("%d", &n);
  while (getchar () != '\n');

  if (n % 2)
    {
      printf ("-1\n");
      return 0;
    }

  for (i = 0; i < n; i ++)
    {
      if (i % 2)
	printf ("%d ", i);
      else
	printf ("%d ", i + 2);
    }
  printf ("\n");
  return 0;
}
