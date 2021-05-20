#include<stdio.h>
#include<stdlib.h>
#define BOOL  int 
#define Ture 1
#define False 1

union{
    int a;
    char b;
}figure;

BOOL IsLittle(){
    figure.a=0x2a3b5c6d;
    if(figure.b==0x6d)
        return Ture;
    else return False;
}

int main(){
    if(IsLittle())
        printf("This computor is little endian!\n");
    else printf("This computor is big endian!\n");
}
