#include<math.h>
#include<stdio.h>
#include<string.h>
#include<limits.h>
#define StrSize 100
void cs_ftoa(double num, char *str1);
void str_reverse(char *strout);
void cs_itoa(int k, char *strout);
int main(){
    double k = 1.123456789;
    char str1[StrSize];
    cs_ftoa(k,str1);
    puts(str1);
}
void cs_ftoa(double num, char *str1){
    char temp_str[StrSize]="\0";
    int temp_int;
    double double_temp;
    double int_temp;
    
    if(num<0){
        strcat(str1,"-");
        num=-num;
    }
    double_temp=modf(num,&int_temp);
    cs_itoa((int)int_temp,temp_str);
    strcat(str1,temp_str);
    if(!double_temp)
        return;
    strcat(str1,".");
    while(double_temp>0.0000001){
        double_temp=double_temp*10;
        double_temp=modf(double_temp,&int_temp);
        cs_itoa((int)int_temp,temp_str);
        strcat(str1,temp_str);
    }
    return;
}

void cs_itoa(int k, char *strout){
    int pt=0;
    char temp[StrSize];
    strout[0]='\0';
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