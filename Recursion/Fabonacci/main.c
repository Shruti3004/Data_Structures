#include <stdio.h>

int fib (int n){
    if (n<=1)
    {
        return n;
    }
    return fib(n-2)+fib(n-1);
    
}

int main(){
    printf("%d",fib(5));
    return 0;
}