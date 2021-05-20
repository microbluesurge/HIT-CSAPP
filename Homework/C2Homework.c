#include<stdio.h> 

typedef unsigned char * BytePointer;
//2.59
void WordCombine_2_59(BytePointer ptx,BytePointer pty, size_t leny){
    size_t i,j;
    printf("0x ");
    printf("%0.2x ",ptx[0]);
    for(i=1;i<leny;i++){
        printf("%0.2x ",pty[i]);
    }
    printf("\n");
}
//2.63
unsigned srl_2_63(unsigned x, int k){
    unsigned xsra = (int) x >> k;
    unsigned temp=0-((x&0x80000000)&&1);
    temp=temp<<(32-k);;
    xsra=xsra^temp;
    return xsra;
}
int ara_2_63(int x, int k){
    int xsrl = (unsigned) x>>k;
    int temp=0-((x&0x80000000)&&1);
    temp=temp<<(32-k);;
    xsrl=xsrl|temp;
    return xsrl;
    
}
/*
2.67 
    源代码的错误在于对于移动超过机器字长的行为未定义，有可能会使程序报错
*/
int IntSizeIs32_2_67(){
    int set_msb = 1<<31;
    int beyond_msb=1<<1;
    beyond_msb = beyond_msb<<31;
    return set_msb && !beyond_msb;
}

int IntSizeIs16_2_67(){
    int set_msb = 1<<15;
    int beyond_msb=1<<1;
    beyond_msb = beyond_msb<<15;
    return set_msb && !beyond_msb;
}

typedef unsigned packed_t;

/*
2.71
    源代码会导致符号位为1时无法扩展为1
*/
int xbyte_2_71(packed_t word, int bytenum){
    word=(word >> (bytenum <<3)) & 0xff;
    int temp=0-((word&0x00000080)&&1);
    temp=temp<<8;
    return word | temp;
}
/*
2.75
    函数如下：
unsigned UnsignedHighProd_2_75(unsigned x, unsigned y){
    unsigned answer = (unsigned) signed_high_prod((int)x,(int)y);
    int XSign= ((x&0x80000000)&&1);
    int YSign= ((y&0x80000000)&&1);
    return answer + XSign*YSign +XSign*y +YSign*x;
}
*/
//2.79
int mul3div4_2_79(int x){
    return ((x + (x<<1))+3*((x&0x80000000)&&1))>>2;
}
/*
2.83
    答案如下：
A 公式为y/（2^k-1）
B(a) 5/7
（b）2/5
（c）19/63
*/
/*
2.87
    答案如下:
描述			Hex		     M		    E		 V		        D
-0            0x8000		0		  -14		-0		      -0.0
最小的>2的值    0x4001		1025/1024	 1		1025*2^(-10)	1.000977
512			  0x6000		1		   24		512		      512.0
最大的非规格化数 0x03FF		2047/1024	 -14	2047*2^(-24)	 0.001952
-∞			  0xFC00		-		   -		-∞		       -∞
0x3BB0		  0x3BB0	  19/16		   0		19*2^(-4)	  1.187500
*/
/*
2.91
A) 11.0010010000111111011011
B) 11.001001001001001......
C) 从二进制小数点之后的第九位开始不一样
*/
//2.95
typedef unsigned float_bits;

float_bits float_half_2_95(float_bits f){
    float_bits temp;
    if(((f&0x7f800000)==0x7f800000)||((f|0x80000000)==0x80000000))
        return f;
    else if((f|0x807fffff)==0x807fffff){
        temp=0x007fffff&f;
        temp=temp>>1;
        f=f&0xff800000;
        return f|temp;
    }
    else if((f|0x807fffff)==0x80ffffff){
        temp=0x007fffff&f;
        temp=temp>>1;
        f=f&0x80000000;
        return f|temp;
    }
    else    return f-0x00800000;
}
//2.95 方便unsigned与float之间进行16进制码赋值转化的函数
void TransFloatToUnsigned_2_95(BytePointer FloatPt, BytePointer UnsignPt){
    for(int i=0;i<4;i++)
       UnsignPt[i]= FloatPt[i];
    return;
}
//2.95 方便float与unsigned之间进行16进制码赋值转化的函数
void TransUnsignedToFloat_2_95(BytePointer FloatPt, BytePointer UnsignPt){
    for(int i=0;i<4;i++)
       FloatPt[i]=UnsignPt[i];
    return;
}
int main(){
    //Test for 2.59
    int x=0x89ABCDEF;
    int y=0x76543210;
    WordCombine_2_59((BytePointer)&x,(BytePointer)&y,sizeof(int));

    //Test for 2.63
    unsigned int tx_2_63=0xaf000000;
    printf("%08x\n",srl_2_63(tx_2_63,8));
    int ty_2_63=0xcf000000;
    printf("%08x\n",ara_2_63(ty_2_63,8));

    //Test for 2.67
    printf("%d\n",IntSizeIs32_2_67());
    printf("%d\n",IntSizeIs16_2_67());

    //Test for 2.71
    printf("%.8x\n",xbyte_2_71(0xfedcba12,1));

    //Test for 2.75
    /*
    无法调用int sign_high_prod(int x, int y)所以测试未给出
    函数部分见上方注释
    */

    //Test for 2.79
    printf("%d\n",mul3div4_2_79(-9));

    //Test for 2.83
    /*
    见上方注释
    */

    //Test for 2.87
    /*
    见上方注释
    */

    //Test for 2.91
    /*
    见上方注释
    */

    //Test for 2.95
    float t1=123.456047;//在此处输入待测试的浮点数值即可s
    unsigned t2=0x40800000;
    TransFloatToUnsigned_2_95((BytePointer)&t1,(BytePointer)&t2);
    t2=float_half_2_95(t2);
    TransUnsignedToFloat_2_95((BytePointer)&t1,(BytePointer)&t2);
    printf("%f\n",t1);
    return 0;

}