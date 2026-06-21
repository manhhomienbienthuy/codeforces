#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
ucln (int a, int b)
{
  int r;
  while (b != 0)
    {
      r = a % b;
      a = b;
      b = r;
    }
  return a;
}

int
main (int argc, char *argv[])
{
  int n, m;
  int p[101], q[101];
  int i, j;

  scanf ("%d %d", &n, &m);
  for (i = 0; i <= n; i++)
    scanf ("%d", &p[i]);
  for (i = 0; i <= m; i++)
    scanf ("%d", &q[i]);

  if (n < m)
    printf ("0/1\n");
  else if (n == m)
    {
      int x = ucln (p[0], q[0]);
      int a = p[0] / x;
      int b = q[0] / x;
      if (b < 0)
	{
	  a = 0 - a;
	  b = 0 - b;
	}
      printf ("%d/%d\n", a, b);
    }
  else
    {
      if ((p[0] * q[0]) < 0)
	printf ("-Infinity\n");
      else
	printf ("Infinity\n");
    }

  return 0;
}
