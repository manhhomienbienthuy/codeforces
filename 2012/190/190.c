#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (int argc, char * argv[])
{
  int n;
  char a[1000000][5];
  char out[100000];
  int i = 0;
  int check, par;

  scanf ("%d\n", &n);
  check = 0;
  
  while (1)
    {
      scanf ("%s", a[i]);
     
      i += 1;
      if (strcmp (a[i-1], "int") == 0)
	check++;
      if (check == n)
	break;
    }

  int num = i;
  
  strcpy (out, a[0]);
  strcat (out, "<");
  check = 1;
  par = 2;
  int pior = 1;

  if (strcmp (a[0], "pair"))
    {
      printf ("Error occurred");
      return 0;
    }

  for (i = 1; i < num; i++)
    {
      if (strcmp (a[i], "pair") == 0)
	{
	  check++;
	  strcat (out, a[i]);
	  strcat (out, "<");
	  par += 2;
	  pior = 1;
	}
      else
	{
	  if (pior == 1)
	    {
	      strcat (out, a[i]);
	      strcat (out, ",");
	      pior = 0;
	      par--;
	    }
	  else
	    {
	    if (par > 0)
	      {
		strcat (out, a[i]);
		strcat (out, ">");
		if (i < num - 1)
		  strcat (out, ",");
		check--;
		par--;
	      }
	}
    }
  if (check > 0)
	strcat (out, ">");

  printf ("%s", out);
  return 0;
}
