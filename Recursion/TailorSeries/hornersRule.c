#include <stdio.h>

double e (int x, int n){
    static double s=1;
    if(n==0){
        return s;
    }        
    else{
        s = 1+(double)x/n*s;
        return e(x,n-1);
    }
}

int main(){
    printf("%lf",e(3,100));
    return 0;
}