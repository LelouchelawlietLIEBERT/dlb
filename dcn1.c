#include <stdio.h>
#include <string.h>

char t[50], cs[20], g[] = "10001000000100001";
int a, e, c, N;

void x() { for (c = 1; c < N; c++) cs[c] = cs[c] == g[c] ? '0' : '1'; }

void crc() {
  for (e = 0; e < N; e++) cs[e] = t[e];
  do {
    if (cs[0] == '1') x();
    for (c = 0; c < N - 1; c++) cs[c] = cs[c + 1];
    cs[c] = t[e++];
  } while (e <= a + N - 1);
}

int main() {
  printf("Enter data: "); scanf("%s", t);
  printf("\n----------------------------------------");
  printf("\nGenerating polynomial: %s", g);
  N = strlen(g); a = strlen(t);
  for (e = a; e < a + N - 1; e++) t[e] = '0'; t[e] = 0;
  printf("\n----------------------------------------");
  printf("\nModified data is: %s", t);
  printf("\n----------------------------------------");
  crc(); cs[N - 1] = 0;
  printf("\nCRC checksum is: %s", cs);
  for (e = a; e < a + N - 1; e++) t[e] = cs[e - a]; t[e] = 0;
  printf("\n----------------------------------------");
  printf("\nFinal codeword transmitted is: %s", t);
  printf("\n----------------------------------------");
  printf("\nTest error detection 0 (yes) 1 (no)? : "); scanf("%d", &e);
  if (!e) {
    do {
      printf("\nEnter the position where error is to be inserted: ");
      scanf("%d", &e);
    } while (e <= 0 || e > a + N - 1);
    t[e - 1] = t[e - 1] == '0' ? '1' : '0';
    printf("\n----------------------------------------");
    printf("\nErroneous data: %s\n", t);
  }
  crc(); cs[N - 1] = 0;
  printf("\nCRC checksum is: %s", cs);
  for (e = 0; e < N - 1 && cs[e] != '1'; e++);
  printf("\n%s detected\n", e < N - 1 ? "Error" : "No error");
  printf("\n----------------------------------------\n");
}

