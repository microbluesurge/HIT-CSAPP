#include<stdio.h>
typedef unsigned char* BytePointer;

//方便float与unsigned之间进行16进制码赋值转化的函数
void TransUnsignedToFloat(BytePointer FloatPt, BytePointer UnsignPt){
    for(int i=0;i<4;i++)
       FloatPt[i]=UnsignPt[i];
    return;
}
int main(){
    unsigned int i1 = 0x00000000, i2 = 0x80000000, i3 = 0x00000001, i4= 0x7f7fffff, i5= 0x00800000,
    i6= 0x7f800000 , i7= 0x7fffffff;
    float j1, j2, j3, j4, j5, j6, j7; 
    TransUnsignedToFloat((BytePointer)&j1, (BytePointer)&i1);
    TransUnsignedToFloat((BytePointer)&j2, (BytePointer)&i2);
    TransUnsignedToFloat((BytePointer)&j3, (BytePointer)&i3);
    TransUnsignedToFloat((BytePointer)&j4, (BytePointer)&i4);
    TransUnsignedToFloat((BytePointer)&j5, (BytePointer)&i5);
    TransUnsignedToFloat((BytePointer)&j6, (BytePointer)&i6);
    TransUnsignedToFloat((BytePointer)&j7, (BytePointer)&i7);

    printf("Positive zero : \n  %f  %0.8x\n",j1,i1);
    printf("Negative zero : \n  %f  %.8x\n",j2,i2);
    printf("Minimun positive float number : \n  %.46f   %.8x\n",j3,i3);
    printf("Maximun positive float number : \n  %f  %.8x\n",j4,i4);
    printf("Minimun positive regular float number : \n  %f  %.8x\n",j5,i5);
    printf("Positive infinity : \n  %f  %.8x\n",j6,i6);
    printf("Not a number : \n  %f  %.8x\n",j7,i7);

}