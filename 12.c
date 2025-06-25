#include <stdio.h>
#include <limits.h>

int g[5][5] = {
    {0, 2, INT_MAX, 12, 5},
    {2, 0, 4, 8, INT_MAX},
    {INT_MAX, 4, 0, 3, 3},
    {12, 8, 3, 0, 10},
    {5, INT_MAX, 3, 10, 0}
};

int p[6], v[5], min = INT_MAX, res[6];

void tsp(int l, int cost) {
    if (l == 5) {
        int total = cost + g[p[4]][p[0]];
        if (total < min) {
            min = total;
            for (int i = 0; i < 5; i++) res[i] = p[i];
            res[5] = p[0];
        }
        return;
    }
    for (int i = 0; i < 5; i++) {
        if (!v[i] && g[p[l-1]][i] != INT_MAX) {
            v[i] = 1;
            p[l] = i;
            tsp(l+1, cost + g[p[l-1]][i]);
            v[i] = 0;
        }
    }
}

int main() {
    p[0] = 0; v[0] = 1;
    tsp(1, 0);
    printf("Cost: %d\nPath: ", min);
    for (int i = 0; i <= 5; i++) printf("%c ", 'A' + res[i]);
}
