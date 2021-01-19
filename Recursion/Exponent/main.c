#include <stdio.h>
#include <math.h>

int power (int m, int n){
    if(n==0){
        return 1;
    }
    return power(m, n-1)*m; 
}

int main(){
    printf("%d",power(2,9));
    return 0;
}