#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char * argv[])
{
  int n, k, i;
  int a[100000];

  scanf ("%d %d", &n, &k);
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }

  for (i = k; i < n; i++)
    if (a[i - 1] != a[i])
      {
	printf ("-1\n");
	return 0;
      }

  for (i = k - 1; i > 0; i--)
    if (a[i - 1] != a[i])
      {
	
	printf ("%d\n", i);
	return 0;
      }

  printf ("0\n");
  return 0;
}
