#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max;
int count;

int min (int a, int b)
{
  return (a < b) ? a : b;
}

void
found (int *a, int n, int i)
{
  int tmp1, tmp2;
  tmp1 = count;
  count = min (count, a[i]);
  if (i == n - 1)
    {
      count = min (count, a[i]);
      if (count > max)
	max = count;
      return;
    }

  if (i < n - 2)
    {
      if (a[i + 1] > a[i + 2])
	{
	  found (a, n, i + 1);
	  count = tmp1;
	}
      else
	{
	  found (a, n, i + 2);
	  count = tmp1;
	}
    }
  else
    {
      found (a, n, i + 1);
      count = tmp1;
    }
}

int
main (int argc, char * argv[])
{
  int n, i;
  int a[1000];

  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }
  count = a[0];
  found (a, n, 0);
  printf ("%d", max);
  return 0;
}
