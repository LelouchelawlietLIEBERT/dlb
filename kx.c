#include <stdio.h>
#include <stdlib.h>
#define INF 99999

typedef struct{int u,v,w;}E;
typedef struct{int V,E;E*edge;}G;

void dprint(int*a,int n){for(int i=0;i<n;i++)printf("%d ",a[i]);puts("");}

void bf(G*g,int s){
    int V=g->V,E=g->E,*d=malloc(V*4),*p=malloc(V*4);
    for(int i=0;i<V;i++)d[i]=INF,p[i]=-1;
    d[s]=0;
    for(int i=1;i<V;i++)
        for(int j=0;j<E;j++){
            int u=g->edge[j].u,v=g->edge[j].v,w=g->edge[j].w;
            if(d[u]!=INF&&d[u]+w<d[v])d[v]=d[u]+w,p[v]=u;
        }
    for(int j=0;j<E;j++){
        int u=g->edge[j].u,v=g->edge[j].v,w=g->edge[j].w;
        if(d[u]!=INF&&d[u]+w<d[v]){puts("Negative cycle");free(d);free(p);return;}
    }
    printf("Distance: ");dprint(d,V);
    printf("Predecessor: ");dprint(p,V);
    free(d);free(p);
}

int main(){
    G*g=malloc(sizeof(G));
    g->V=4;g->E=5;
    g->edge=malloc(g->E*sizeof(E));
    g->edge[0]=(E){0,1,5}; g->edge[1]=(E){0,2,4};
    g->edge[2]=(E){1,3,3}; g->edge[3]=(E){2,1,6};
    g->edge[4]=(E){3,2,2};
    bf(g,0);
    free(g->edge);free(g);
}

