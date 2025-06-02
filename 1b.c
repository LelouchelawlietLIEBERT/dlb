#include <stdio.h>
#include <limits.h>

#define N 4
int g[N][N]={{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}};

int main() {
    int min=INT_MAX, path[N+1];
    for(int s=0;s<N;s++){
        int vis[N]={0}, cost=0, u=s, p[N+1]; p[0]=u; vis[u]=1;
        for(int i=1;i<N;i++){
            int n=-1,d=INT_MAX;
            for(int j=0;j<N;j++)
                if(!vis[j]&&g[u][j]<d) d=g[u][j],n=j;
            vis[n]=1; cost+=d; u=n; p[i]=u;
        }
        cost+=g[u][s]; p[N]=s;
        if(cost<min){ min=cost; for(int i=0;i<=N;i++) path[i]=p[i]; }
    }
    printf("Cost: %d\nPath: ",min);
    for(int i=0;i<=N;i++) printf("%d ",path[i]);
}
