#include <stdio.h>
#define V 5
#define I 9999

int m(int d[], int v[]) {
  int x = -1, m = I;
  for (int i = 0; i < V; i++) if (!v[i] && d[i] <= m) m = d[i], x = i;
  return x;
}

int dijk(int g[V][V], int s, int t) {
  int d[V], v[V] = {0};
  for (int i = 0; i < V; i++) d[i] = I;
  d[s] = 0;
  for (int i = 0; i < V - 1; i++) {
    int u = m(d, v);
    if (u == -1) break;
    v[u] = 1;
    for (int j = 0; j < V; j++)
      if (!v[j] && g[u][j] && d[u] + g[u][j] < d[j]) d[j] = d[u] + g[u][j];
  }
  return d[t];
}

int main() {
  int g[V][V] = {{0,10,0,0,5},{0,0,1,0,2},{0,0,0,4,0},{7,0,6,0,0},{0,3,9,2,0}}, s, t;
  printf("Enter source node (0 to %d): ", V-1); scanf("%d", &s);
  printf("Enter destination node (0 to %d): ", V-1); scanf("%d", &t);
  if (s<0||s>=V||t<0||t>=V) return printf("Invalid input. Nodes must be between 0 and %d.\n", V-1),1;
  int d = dijk(g, s, t);
  d != I ? printf("Shortest distance from %d to %d is: %d\n", s, t, d)
        : printf("No path exists from %d to %d\n", s, t);
  return 0;
}

