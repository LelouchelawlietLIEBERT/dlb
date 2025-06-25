#include <stdio.h>
int w[]={3,5,6,2},v[]={10,4,9,11},n=4,W=7,dp[5][8];
int max(int a,int b){return a>b?a:b;}
int main(){
  for(int i=1;i<=n;i++)
    for(int j=0;j<=W;j++)
      dp[i][j]=j<w[i-1]?dp[i-1][j]:max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
  printf("Max:%d\nItems:",dp[n][W]);
  for(int i=n,j=W;i;i--)
    if(dp[i][j]!=dp[i-1][j]) printf("%d ",i),j-=w[i-1];
}
