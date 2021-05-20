#include<stdio.h>
#include<string.h>
int cs_atoi(char * str1){
    int ret = 0,length = strlen(str1);
    for(int i = 0;i<length; i++)
        ret=ret*10+str1[i]-'0';
    return ret;
}
int main(){
    char tt[100]="10068";
    printf("%d\n",cs_atoi(tt));
}