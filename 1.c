#include <stdio.h>
#include <stdbool.h>

#define N 3

bool womanPrefersNewMan(int wp[N][N], int woman, int newMan, int currentMan) {
    for (int i = 0; i < N; i++) {
        if (wp[woman][i] == newMan)
            return true;
        if (wp[woman][i] == currentMan)
            return false;
    }
    return false;
}

void stableMatch(int mp[N][N], int wp[N][N]) {
    int womanPartner[N];   
    bool manFree[N];      
    int nextProposal[N] = {0};
    int freeCount = N;

    for (int i = 0; i < N; i++) {
        womanPartner[i] = -1;
        manFree[i] = true;
    }

    while (freeCount > 0) {
        int m;
        for (m = 0; m < N; m++)
            if (manFree[m])
                break;

        int w = mp[m][nextProposal[m]++];

        if (womanPartner[w] == -1) {
            womanPartner[w] = m;
            manFree[m] = false;
            freeCount--;
        } else {
            int m1 = womanPartner[w];
            if (womanPrefersNewMan(wp, w, m, m1)) {
                womanPartner[w] = m;
                manFree[m] = false;
                manFree[m1] = true;
            }
        }
    }

    printf("Woman  -  Man\n");
    for (int i = 0; i < N; i++)
        printf("  %d     -   %d\n", i, womanPartner[i]);
}

int main() {
    int mp[N][N] = {
        {0, 1, 2},
        {2, 0, 1},
        {1, 2, 0}
    };

    int wp[N][N] = {
        {0, 1, 2},
        {2, 0, 1},
        {1, 2, 0}
    };

    stableMatch(mp, wp);

    return 0;
}
