#include <stdio.h>
int main() {
    int d[10], r[10], i, c1, c2, c3, c;

    printf("Enter 4 bits of data one by one:\n");
    scanf("%d%d%d%d", &d[0], &d[1], &d[2], &d[4]);

    d[6] = d[0] ^ d[2] ^ d[4];
    d[5] = d[0] ^ d[1] ^ d[4];
    d[3] = d[0] ^ d[1] ^ d[2];

    printf("\nEncoded data is: ");
    for (i = 0; i < 7; i++) printf("%d", d[i]);

    printf("\n\nEnter received data bits one by one:\n");
    for (i = 0; i < 7; i++) scanf("%d", &r[i]);

    c1 = r[6] ^ r[4] ^ r[2] ^ r[0];
    c2 = r[5] ^ r[4] ^ r[1] ^ r[0];
    c3 = r[3] ^ r[2] ^ r[1] ^ r[0];
    c = c3 * 4 + c2 * 2 + c1;

    if (!c) printf("\nNo error while transmission of data.\n");
    else {
        printf("\nError on position %d\n", c);
        printf("Data sent     : "); for (i = 0; i < 7; i++) printf("%d", d[i]);
        printf("\nData received : "); for (i = 0; i < 7; i++) printf("%d", r[i]);
        r[7 - c] ^= 1;
        printf("\nCorrected data: "); for (i = 0; i < 7; i++) printf("%d", r[i]);
        printf("\n");
    }
    return 0;
}
