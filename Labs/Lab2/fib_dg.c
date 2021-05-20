#include<stdio.h>

int fib_dg(int n);
int main(){
    printf("%d\n",fib_dg(10));
}


int fib_dg(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else return fib_dg(n-1)+fib_dg(n-2);
}