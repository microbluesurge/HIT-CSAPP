#include<stdio.h>
#include<string.h>

#define StrSize 1000


int utf8len(char *str1){
    int length,counter=0,i=0;
    length=strlen(str1);
    printf("%d\n",length);
    while(i<length){
        if(!(str1[i]&0x80)){
            counter++;
            i+=1;
        }
        else if(!(str1[i]&0x20)){
            counter++;
            i+=2;
        }
        else if(!(str1[i]&0x10)){
            counter++;
            i+=3;
        }
        else{
            counter++;
            i+=4;
        }
    }
    return counter;
}
int main(){
    char tt[StrSize]="林搏海1190202128";
    printf("%d\n",utf8len(tt));
}