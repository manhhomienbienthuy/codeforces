#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  int n;
  char s[101], a[100];
  int i, sl, sr;
  FILE *fi, *fo;

  fi = fopen ("input.txt", "r");
  fo = fopen ("output.txt", "w");
  
  fscanf (fi, "%d\n", &n);
  fscanf (fi, "%s", s);

  for (i = 0; i < n / 2; i++)
    {
      if (s[i] == 'R' && s[n/2 + i] == 'L')
	fprintf (fo, "%d %d\n", n/2 + i + 1, i + 1);
      else
	fprintf (fo, "%d %d\n", i + 1, n/2 + i + 1);
    }

  fclose (fi);
  fclose (fo);
  return 0;
}
