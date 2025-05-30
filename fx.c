#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define P 8080
#define B 1024

int main() {
  int s=socket(2,1,0);
  struct sockaddr_in a={0};
  a.sin_family=2; a.sin_port=htons(P);
  inet_pton(2,"127.0.0.1",&a.sin_addr);
  connect(s,(struct sockaddr*)&a,sizeof(a));
  char b[B]={0},f[100];
  printf("Enter filename: ");
  fgets(f,100,stdin);
  f[strcspn(f,"\n")]=0;
  send(s,f,strlen(f),0);
  int r;
  while((r=recv(s,b,B-1,0))>0) {
    b[r]=0; printf("%s",b);
  }
  close(s);
  return 0;
}

