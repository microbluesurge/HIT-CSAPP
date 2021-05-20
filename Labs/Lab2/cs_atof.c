#include<string.h>
#include<stdio.h>

double cs_atof(char *str1){
    int length = strlen(str1);
    double pow = 0.1,ret=0;
    for(int i =0; i<length; i++){
        if('0'<=str1[i]&&str1[i]<='9')
            ret = ret*10 + (str1[i]-'0');
        else if(i==length-1)
            break;
        else {
            
            while(i<length-1){
                ret = ret + pow*(double)(str1[++i]-'0');
                pow = pow * 0.1;
                printf("%.20lf ttt\n",ret);
            }
        }
    }
    return ret;
}

int main(){
    char tt[100]="123789.456321";
    printf("%.20lf\n",cs_atof(tt));
}