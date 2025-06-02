#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#define P 8080
#define B 1024

int main() {
  int s = socket(2,1,0), ns;
  struct sockaddr_in a = {0};
  a.sin_family=2; a.sin_addr.s_addr=0; a.sin_port=htons(P);
  bind(s,(struct sockaddr*)&a,sizeof(a));
  listen(s,3);
  ns=accept(s,(struct sockaddr*)&a,(socklen_t[]){sizeof(a)});
  char b[B]={0};
  recv(ns,b,B,0);
  FILE *f=fopen(b,"r");
  if(!f) send(ns,"Error: File not found.\n",22,0);
  else while(fgets(b,B,f)) send(ns,b,strlen(b),0);
  close(ns); close(s);
  return 0;
}

