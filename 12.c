#include <stdio.h>
#include <limits.h>

#define N 5

int g[N][N] = {
    {0, 2, INT_MAX, 12, 5},
    {2, 0, 4, 8, INT_MAX},
    {INT_MAX, 4, 0, 3, 3},
    {12, 8, 3, 0, 10},
    {5, INT_MAX, 3, 10, 0}};

int p[N + 1], v[N] = {0}, min_cost = INT_MAX, res[N + 1];

void tsp(int l, int cost)
{
    if (l == N)
    {
        if (g[p[N - 1]][p[0]] != INT_MAX)
        {
            int total = cost + g[p[N - 1]][p[0]];
            if (total < min_cost)
            {
                min_cost = total;
                for (int i = 0; i < N; i++)
                    res[i] = p[i];
                res[N] = p[0];
            }
        }
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!v[i] && g[p[l - 1]][i] != INT_MAX)
        {
            v[i] = 1;
            p[l] = i;
            tsp(l + 1, cost + g[p[l - 1]][i]);
            v[i] = 0;
        }
    }
}

int main()
{
    p[0] = 0;
    v[0] = 1;
    tsp(1, 0);

    if (min_cost == INT_MAX)
        printf("No valid tour found.\n");
    else
    {
        printf("Minimum Cost: %d\nPath: ", min_cost);
        for (int i = 0; i <= N; i++)
            printf("%c ", 'A' + res[i]);
        printf("\n");
    }

    return 0;
}
