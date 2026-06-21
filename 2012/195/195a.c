#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  int a, b, c;
  scanf ("%d %d %d", &a, &b, &c);

  int unit = a * c;
  int s = unit/b - c;
  if ((s + c) * b >= unit)
    printf ("%d\n", s);
  else
    printf ("%d\n", s + 1);
  return 0;
}
