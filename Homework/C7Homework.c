#include<stdio.h>
/*
//7.7
//修改后的bar5.c
static double x
void f(){
    x = -0.0; 
}

//将x前面加上static声明，使其不能foo.c访问
*/


/*
7.9
由于在foo6.c中声明了强符号int main()
而在bar6.c中声明的全局变量main未被赋值，因此为弱符号
所以链接器采用强符号定义
因此程序可以正常终止
*/

/*
7.11
因为有8个字节的被赋值为0的全局变量内容被放在.BSS中，不会为其分配存储空间
*/


int main(){

    return 0;
}