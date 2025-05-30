#include <stdio.h>

int main() {
    int in, out, cap, n, buf = 0;

    printf("Enter bucket capacity, outgoing rate, and number of inputs: ");
    scanf("%d %d %d", &cap, &out, &n);

    while (n--) {
        printf("\nEnter the number of incoming packets: ");
        scanf("%d", &in);
        printf("Incoming packet size: %d\n", in);

        if (in <= cap - buf) buf += in;
        else {
            int drop = in - (cap - buf);
            buf = cap;
            printf("%d packets dropped!\n", drop);
        }

        int sent = (buf >= out) ? out : buf;
        buf -= sent;

        printf("%d packets sent out\n", sent);
        printf("%d out of %d space used in the buffer\n", buf, cap);
    }

    return 0;
}

