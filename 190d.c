#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
cmp (const void *a, const void *b)
{
  int x = *((int*)a);
  int y = *((int*)b);
  if (x < y)
    return -1;
  else if (x == y)
    return 0;
  return 1;
}

int
check (int *a, int start, int stop, int k)
{
  int i, std, count;
  int *b = (int*) malloc (sizeof (int) * (stop-start + 1));

  for (i = start; i < stop; i++)
    b[i-start] = a[i];
  qsort (b, stop - start, sizeof (int), cmp);
  b[stop - start] = b[stop - start -1] - 1;
  std = b[0];
  count = 1;
  for (i = 1; i <= stop - start; i++)
    {
      if (b[i] != std)
	{
	  std = b[i];
	  if (count >= k)
	    {
	      free (b);
	      return 1;
	    }
	  count = 1;
	}
      else
	count++;
    }
  return 0;
}

int
main (int argc, char *argv[])
{
  int n, k;
  int a[400000];
  int i, j, count = 0;

  scanf ("%d %d", &n, &k);
  for (i = 0; i < n; i++)
    scanf ("%d", a + i);

  for (i = 0; i <= n - k; i++)
    for (j = i + k - 1; j <= n; j++)
      if (check (a, i, j, k))
	{
	  /* printf ("%d %d:\n", i, j);  */
	  count++;
	}

  printf ("%d\n", count);
  return 0;
}
