#include <stdio.h>

int main(){
    int A[5];
    int B[5] = {2,4,6,8,10};
    int C[5] = {2,4,6};
    int D[5] = {0};
    int E[] = {1,2,3,4,5};

    for(int i=0; i<5; i++){
        // printf("%d ", E[i]);
        // For printing addresses
        printf("%u \n", &A[i]);
    }
    return 0;
}