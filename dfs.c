#include <stdio.h>
#include <stdlib.h>

int *adj[100], deg[100], vis[100], q[100]; // adjacency list, degree, visited, queue

int main() {
    int V, E, i, u, v, src, f = 0, r = 0;

    scanf("%d%d", &V, &E); // input number of vertices and edges
    while (E--) {
        scanf("%d%d", &u, &v);
        // allocate space for each new adjacent node (4 bytes = sizeof(int))
        adj[u] = realloc(adj[u], ++deg[u]*4);
        adj[u][deg[u]-1] = v;
    }

    scanf("%d", &src);     // input source node
    q[r++] = src;          // enqueue source
    vis[src] = 1;

    while (f < r) {        // BFS loop
        u = q[f++];        // dequeue
        printf("%d ", u);  // print current node
        for (i = 0; i < deg[u]; i++) {
            if (!vis[adj[u][i]]) {
                q[r++] = adj[u][i];      // enqueue neighbor
                vis[adj[u][i]] = 1;      // mark as visited
            }
        }
    }
}
