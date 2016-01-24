#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max;
char str[500000];
char a[500000][11];

int
check_first (int n, int i)
{
  int flag;
  int j;

  if (i == 0)
    {
      for (j = 1; j < n; j++)
	if (j != i)
	  if (a[i][strlen (a[i]) -1] == a[j][0])
	    return 1;
      return 0;
    }

  if (i == n)
    {
      for (j = 0; j < n - 2; j++)
	if (j != i)
	  if (a[i][0] == a[j][strlen (a[j]) - 1])
	    return 1;
      return 0;
    }

  for (j = 0; j < n; j++)
    if (i != j)
      {
	if (a[i][strlen (a[i]) -1] == a[j][0])
	  return 1;
	if (a[i][0] == a[j][strlen (a[j]) - 1])
	  return 1;
      }
  return 0;
}

void
found (int n, int i)
{
  int j;
  char tmp[500000];

  strcpy (tmp, str);
  for (j = i + 1; j < n; j++)
    {
      if (a[i][strlen (a[i]) - 1] == a[j][0])
	{
	  strcat (str, a[j]);
	  if (a[j][strlen (a[j]) - 1] == str[0])
	    if (strlen (str) > max)
	      max = strlen (str);
	  found (n, j);
	  strcpy (str, tmp);
	}
      strcpy (str, tmp);
    }
}

int
main (int argc, char *argv[])
{
  int n;
  int i, j;

  scanf ( "%d", &n);
  while (getchar () != '\n');
  max = 0;
 
  for (i = 0; i < n; i++)
    {
      gets (a[i]);
      if (strlen (a[i]) == 1)
	max = 1;
    }
 
  strcpy (str, "");
 
  for (i = 0; i < n; i++)
    {
      if (a[i][0] == a[i][strlen (a[i]) - 1])
	if (strlen (a[i]) > max)
	  max = strlen (a[i]);
    }

  i = 0;
  while (i < n)
    {
      if (check_first (n, i) == 0)
	{
	  for (j = i + 1; j < n; j++)
	    {
	      strcpy (a[j], a[j + 1]);
	    }
	  n--;
	  continue;
	}
      i++;
    }

  for (i = 0; i < n; i++)
    {
      strcpy (str, a[i]);
      found (n, i);
    }
  printf ("%d", max);
  return 0;
}
