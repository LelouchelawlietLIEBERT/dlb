#include <stdio.h>
#include <stdlib.h>

typedef struct{int s,f,v;}J;
int cmp(const void*a,const void*b){return ((J*)a)->f-((J*)b)->f;}
int latest(J a[],int i){
  for(int j=i-1;j>=0;j--) if(a[j].f<=a[i].s) return j;
  return -1;
}
int main(){
  J a[]={{1,2,100},{2,5,200},{3,6,300},{4,8,400},{5,9,500},{6,10,100}};
  int n=6,dp[6];
  qsort(a,n,sizeof(J),cmp);
  dp[0]=a[0].v;
  for(int i=1;i<n;i++){
    int l=latest(a,i),inc=a[i].v+(l==-1?0:dp[l]);
    dp[i]=dp[i-1]>inc?dp[i-1]:inc;
  }
  printf("Max Profit:%d\n",dp[n-1]);
}
