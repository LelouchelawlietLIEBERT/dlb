#include <stdio.h>
#include <limits.h>
#define N 5
int g[N][N]={{0,2,0,6,0},{2,0,3,8,5},{0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0}};
int main(){
    int k[N],p[N],m[N]={0},i,j,u,c=0; 
    for(i=0;i<N;i++) k[i]=INT_MAX; 
    k[0]=0; p[0]=-1;
    for(i=0;i<N-1;i++){
        int min=INT_MAX;
        for(j=0;j<N;j++) if(!m[j]&&k[j]<min) min=k[j],u=j;
        m[u]=1;
        for(j=0;j<N;j++)
            if(g[u][j]&&!m[j]&&g[u][j]<k[j]) p[j]=u,k[j]=g[u][j];
    }
    for(i=1;i<N;i++) printf("%d-%d:%d\n",p[i],i,g[i][p[i]]),c+=g[i][p[i]];
    printf("Total:%d\n",c);
}
