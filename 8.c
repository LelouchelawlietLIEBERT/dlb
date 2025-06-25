#include <stdio.h>
#include <limits.h>
#define N 5

int cost[N][N] = {{0,10,0,0,5},{10,0,1,6,0},{0,1,0,2,7},{0,6,2,0,3},{5,0,7,3,0}};

int main(){
    int sel[N] = {0},edge = 0,total=0;
    sel[0]=1;
    while(edge++<N-1){
        int min = INT_MAX,x,y;
        for(int i=0;i<N;i++){
            if(sel[i]){
                for(int j=0;j<N;j++){
                    if(!sel[j]&&cost[i][j]&&cost[i][j]<min){
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("edge %d - %d , cost : %d\n",x+1,y+1,cost[x][y]);
        total+=cost[x][y];
        sel[y]=1;
    }
    printf("Total cost : %d",total);
}
