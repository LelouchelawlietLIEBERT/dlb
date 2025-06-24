#include <stdio.h>
#define MAX 100
#define INF 1000000

int main() {
    int V, E, u[MAX], v[MAX], w[MAX], dist[MAX];
    int i, j, src;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < E; i++)
        scanf("%d %d %d", &u[i], &v[i], &w[i]);

    printf("Enter source: ");
    scanf("%d", &src);

    for (i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;

    for (i = 1; i < V; i++)
        for (j = 0; j < E; j++)
            if (dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]])
                dist[v[j]] = dist[u[j]] + w[j];

    for (j = 0; j < E; j++)
        if (dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]) {
            printf("Negative weight cycle detected\n");
            return 0;
        }

    printf("Vertex\tDistance\n");
    for (i = 0; i < V; i++)
        printf("%d\t%s\n", i, dist[i] == INF ? "INF" : (printf("%d", dist[i]), ""));

    return 0;
}
