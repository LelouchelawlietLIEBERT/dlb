#include <stdio.h>

__global__ void add(int *a, int *b, int *c){
    *c = *a + *b;
}

int main(){
    int a = 5, b = 7, c;
    int *da, *db, *dc;

    cudaMalloc(&da, sizeof(int));
    cudaMalloc(&db, sizeof(int));
    cudaMalloc(&dc, sizeof(int));

    cudaMemcpy(da, &a, sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(db, &b, sizeof(int), cudaMemcpyHostToDevice);

    add<<<1,1>>>(da, db, dc);

    cudaMemcpy(&c, dc, sizeof(int), cudaMemcpyDeviceToHost);

    printf("Sum = %d\n", c);

    cudaFree(da); cudaFree(db); cudaFree(dc);
    return 0;
}
