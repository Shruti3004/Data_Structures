#include <stdio.h>

int fact (int n){
    if(n==0){
        return 1;
    }
    return fact(n-1)*n;
}

int nCr (int n, int r){
    int num, den;
    num =fact(n);
    den = fact(n-r)*fact(r);
    return num/den;
}

int NCR (int n, int r){
    if(n==r||r==0){
        return 1;
    }
    return NCR(n-1,r-1)+ NCR(n-1,r);
}

int main(){
    // printf("%d",nCr(5,1));
    printf("%d",NCR(5,2));
    return 0;
}