#include <stdio.h>
#include <limits.h>
#define N 5

int cost[N][N] = {{0,4,0,8,0},{4,0,3,1,0},{0,3,0,7,8},{8,1,7,0,3},{0,0,8,3,0}};

int main(){
    int vis[N] = {0},path[N],total=0,curr=0;
    path[0] = curr;
    vis[curr] = 1;
    for(int count=1;count<N;count++){
        int next=-1,min=INT_MAX;
        for(int j=0;j<N;j++){
            if(!vis[j] && cost[curr][j] && cost[curr][j]<min){
                min = cost[curr][j];
                next = j;
            }
        }
        if(next==-1) break;
        vis[next] = 1;
        path[count] = next;
        total+=min;
        curr = next;
    }
    printf("Total cost : %d\n",total);
    printf("Path : \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d\t",path[i]+1);
    }
    
    return 0;
}
