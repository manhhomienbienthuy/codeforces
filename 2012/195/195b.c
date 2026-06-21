#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  int n, m;
  int i, j;
  int mi = 0;

  scanf ("%d %d", &n, &m);
  int *a = (int *) malloc (n * sizeof (int));
  int *b = (int *) malloc (m * sizeof (int));
  int mid = (m + 1)/2;
  float midle = (m + 1) / 2.0;

  if (m > 1)
    {
      for (i = 0; i < n; i++)
	a[i] = 0;
    }
  else
    {
      for (i = 0; i < n; i++)
	a[i] = 1;
    }

  for (i = 0; i < m; i++)
    b[i] = 0;
  int k = 1;
  if (m > 1)
    {
      if (((m + 1) % 2) == 0)
	{
	  a[0] = mid;
	  j = 1;
	  
	  for (i = 1; i < n; i++)
	    {
	      if (j > m - mid)
		j = 0;
	      if ((i % 2) == k)
		a[i] = mid - j;
	      else
		{
		  a[i] = mid + j;
		  j++;
		  if (j > m - mid)
		    {
		      a[++i] = mid;
		      j = 1;
		      if (k == 1)
			k = 0;
		      else
			k = 1;
		    }
		}
	    }
	}
      else
	{
	  a[0] = (int) midle;
	  a[1] = (int) midle + 1;
	  float k = 1.5;
	  if (k > m - midle)
	    k = 0.5;
	  for (i = 2; i < n; i++)
	    {
	      if ((i % 2) == 0)
		a[i] = (int)(midle - k);
	      else
		{
		  a[i] = (int)(midle + k);
		  k = k + 1;
		  if (k > m - midle)
		    k = 0.5;
		}
	    }
	}
    }

  for (i = 0; i < n; i++)
    printf ("%d\n", a[i]);

  free (a);
  free (b);
  return 0;
}
