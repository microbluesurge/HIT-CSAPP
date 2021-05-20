#include<stdio.h>
#include<limits.h>
#include<string.h>

#define StrSize 1000

void cs_itoa(int k, char *strout);
void str_reverse(char *strout);

int main(){
    int k = INT_MAX;
    char tt[StrSize]="\0";
    cs_itoa(k , tt);
    puts(tt);
    return 0;
}
void cs_itoa(int k, char *strout){
    int pt=0;
    char temp[StrSize];
    if(k==INT_MIN){
        strcpy(strout,"-2147483648");
        return;
    }
    else if(k==0){
        strcpy(strout,"0");
        return;
    }
    else if(k<0){
        strout[0]='-';
        k=-k;
    } 
    while(k!=0){
        temp[pt++]=k%10 + '0';
        k = k/10;
    }
    temp[pt]='\0';
    str_reverse(temp);
    strcat(strout,temp);
    return;
}

void str_reverse(char *strout){
    int len=strlen(strout);
    for(int i = 0, j = len - 1; i < j; i++, j--){
        char temp = strout[i];
        strout[i] = strout[j];
        strout[j] = temp; 
    }
}
