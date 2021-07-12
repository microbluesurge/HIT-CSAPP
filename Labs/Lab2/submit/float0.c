#include<stdio.h>

typedef unsigned char* BytePointer;

int main(){
    float a = 2;
    float b = 0;
    float c = 0.00000000000000000000001;
    printf("Result of devide by zero : \n   %f\n",a/b);
    printf("Result of devide by small number : \n   %f\n",a/c);
}