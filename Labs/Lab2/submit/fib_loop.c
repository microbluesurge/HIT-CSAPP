#include<stdio.h>

#define Datatype unsigned int 

Datatype fib_loop(Datatype n);

int main(){
    printf("%u\n",fib_loop(48));
}

Datatype fib_loop(Datatype n){
    if(n==0)
        return 0;
    else if(n==1||n==2)
        return 1;
    else {
        Datatype sum = 1, temp = 0, prev =1;
        for(Datatype i = 3; i <= n; i++){
            temp=sum;
            sum= sum + prev;
            prev=temp;
        }
        return sum;
    }
}