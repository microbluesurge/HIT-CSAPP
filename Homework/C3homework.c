#include<stdio.h>
#include<string.h>
#define  SizeStr 1000

/*
2.59
    由于x*y=(2^64*xh+xl)(2^64*yh+yl)
    =2^128*xh*yh+2^64(xh*yl+xl*yh)+xl*yl
    可以知道结果的低64位的值为xl*yl的低64位值
    结果的高64位值为xh*yl+xl*yh的低64位值加上xl*yl的高64位值
    根据过程参数传递规则可以知道x，y分别被存放在%rsi，%rdx中
    汇编代码第二行将y符号扩展，yh被存放在了%rdx中
    第5行将%rcx中x的值符号右移63位，相当于将xh存放在了%rcx中
    第6,7航分别计算了yl*xh和xl*yh的值
    第8行将其求和放在了%rcx中
    第9行计算了xl*yl的值并将低64位放在了%rax，高64位放在了%rdx
    第10行将xh*yl+xl*yh低64位和xl*yl的高64位相加放在了%rdx
    第11,12将结果按照小端续放在栈中
*/

/*
3.61
*/
long cread(long *xp){
    return (xp ? 0 : *xp);
}


/*
3.63
*/
long switch_prob(long x, long n){
    long result = x;
    switch(n){
        case 60:
        case 62:
            result = 8*x;
            break;
        case 63:
            result = x >> 3;
            break;
        case 64:
            result = (x << 4) - x;
            x = result;
        case 65:
            x = x * x;
        default:
            result = x + 75;
    }
    return result;
}

/*
3.65
A. %rdx
B. %rax
C. 15
*/

/*
3.67

A.
    相对地址        栈值
    ......      ......
    %rsp+24     z
    %rsp+16     &z
    %rsp+8      y
    %rsp        x

B.  传递了%rdi中的地址，并通过运行时栈传递了所有strA s中的元素

C.  使用%rsp加上偏移量
D.  
    相对地址        栈值
    ......      ......
    %rsp+88     q
    %rsp+80     u[1]
    %rsp+72     u[0]
    ......      ......
    %rsp+24     &z
    %rsp+16     y
    %rsp+8      x
    %rsp        Return Address

E.  结构体通过存储在运行时栈上完成参数传递，函数通过寄存器返回结构体指针
*/

/*
3.69
A. CNT=7;
B. 
    typedef struct{
        long idx;
        long x[4];
    }a_struct;
*/

/*
3.71
*/
void good_echo(void){
    char buffle[SizeStr];
    while (fgets(buffle, SizeStr, stdin) != NULL){
        printf("%s", buffle);
        if (ferror(stdin)) {
            printf("\nError\n");
            return;
		}
	}
}

int main(){
    
    int n;
    //good_echo();
    printf("hhhh\n");
    
    scanf("%d",&n);
    printf("%d",n);
    

    return 0;
}