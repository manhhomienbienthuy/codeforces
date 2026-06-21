#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 
cmp (const void *a, const void *b)
{
  int x = *(int *)a;
  int y = *(int *)b;

  if (x == y)
    return 0;
  if (x < y)
    return -1;
  return 1;
}

int
main (int argc, char *argv[])
{
  int n, i;
  int a[100000];
  
  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]); 
    }

  int min = 0;

  for (i = 1; i < n; i++)
    if (a[i] < a[min])
      min = i;

  int check = 0;
  for (i = 0; i < n; i++)
    if (a[i] == a[min])
      check++;

  if (check > 1)
    printf ("Still Rozdil\n");
  else
    printf ("%d\n", min + 1);
  return 0;
}


