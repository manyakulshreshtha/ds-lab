#include <stdio.h>
#include <conio.h>
void bfs(int a[20][20], int n, int src, int t[20][2], int s[],int *k)
{
  int f, r, q[20], u, v, i;
  for (i = 0; i < n; i++)
    s[i] = 0;
  f = r = 0;
 *k=0;
  q[r] = src;
  s[src] = 1;
  while (f <= r)
  {
    u = q[f++];
    for (v = 0; v < n; v++)
    {
      if (a[u][v] == 1 && s[v] == 0)
      {
        s[v] = 1;
        q[++r] = v;
        t[*k][0] = u;
        t[*k][1] = v;
        (*k)++;
      }
    }
  }
}
void main()
{
  int n, a[20][20], src, t[20][2], flag, s[20], i, j;
  printf("Enter the number of nodes\n");
  scanf("%d", &n);
  printf("Enter the adjacency matrix\n");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
  }
  printf("Enter the source\n");
  scanf("%d", &src);
  int k;
  bfs(a, n, src, t, s,&k);
  flag = 0;
  for (i = 0; i < n; i++)
  {
    if (s[i] == 0)
    {

      printf("Vertex %d is not reachable\n", i);
      flag = 1;
    }
    else
      printf("Vertex %d is reachable\n", i);
  }
  if (flag == 1)
    printf("Some nodes are not visited\n");
  else
  {
    printf("The BFS traversal is\n");
    for (i = 0; i < k; i++)
      printf("%d->%d\n", t[i][0], t[i][1]);
  }
  getch();
}