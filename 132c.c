#include <stdio.h>
#include <string.h>

#define LMT 105

char work[LMT];
int len, n, dp[2][LMT << 1][LMT][52];

int
max (int x, int y)
{
  return x > y ? x : y;
}

int
dfs (int dre, int pos, int i, int cn)
{
  if (cn < 0)
    return 0;

  if (!work[i])
    return cn > 0 ? 0 : abs (pos);

  if (dp[dre][pos + 100][i][cn] != -1)
    return dp[dre][pos + 100][i][cn];

  int mv = dre ? 1 : -1;
  int x = dfs (dre, pos + mv, i + 1, cn - (work[i] != 'F'));
  int y = dfs (!dre, pos, i + 1, cn - (work[i] != 'T'));
  dp[dre][pos + 100][i][cn] = max (x, y);
  return dp[dre][pos + 100][i][cn];
}

int
main ()
{
  int ans = 0;
  scanf ("%s%d", work, &n);
  memset (dp, -1, sizeof (dp));
  for (; n >= 0; n -= 2)
    ans = max (ans, dfs (1, 0, 0, n));
  printf ("%d\n", ans);
  return 0;
}
