#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define StrSIZE 100
typedef unsigned char *BytePointer;
struct LoverDate
{
    char LoverName[StrSIZE];
    double date;
};

union LoverHeight
{
    char Abbr;
    double Height;
};

//enum g {male, female, others};

int LoverWeight = 55;
char LoverAbbr = 'G';
float LoverBirthday = 12.05;
double LoverSpell = 5201314.999;
char *LoverAbbrPt = &LoverAbbr;
unsigned int LoveLimit = 10000;
int LoverBWH[3] = {93,63,90};

void ShowBytes(BytePointer pt,size_t len)
{
    size_t i;
    for(i=0;i<len;i++)
    {
        printf("%0.2x ",pt[i]);
    }
    printf("\n");
    
}

int main(void)
{
    struct LoverDate cy;
    strcpy(cy.LoverName, "chengyuan");
    cy.date = 10.24;

    union LoverHeight CyHeight;
    CyHeight.Abbr = 'C';
    CyHeight.Height = 168.55;

    printf("Case 1 : \n");
    printf("    Variable Type : Struct \n");
    printf("    Variable Name : cy \n");
    printf("    Variable Content : %s %lf \n",cy.LoverName,cy.date);
    printf("    Variable Address : %p \n",&(cy.LoverName));
    printf("    Variable Hex Value : \n        ");
    ShowBytes((BytePointer)&(cy.LoverName), sizeof(cy.LoverName));

    printf("Case 2 : \n");
    printf("    Variable Type : Union \n");
    printf("    Variable Name : CyHeight \n");
    printf("    Variable Content : %c %lf \n",CyHeight.Abbr,CyHeight.Height);
    printf("    Variable Address : %p \n",&(CyHeight.Height));
    printf("    Variable Hex Value : ");
    ShowBytes((BytePointer)&(CyHeight.Height), sizeof(CyHeight.Height));

    printf("Case 3 : \n");
    printf("    Variable Type : Int \n");
    printf("    Variable Name : LoverWeight \n");
    printf("    Variable Content : %d \n",LoverWeight);
    printf("    Variable Address : %p \n",&(LoverWeight));
    printf("    Variable Hex Value : ");
    ShowBytes((BytePointer)&LoverWeight, sizeof(LoverWeight));

    printf("Case 4 : \n");
    printf("    Variable Type : Char \n");
    printf("    Variable Name : LoverAbbr \n");
    printf("    Variable Content : %c \n",LoverAbbr);
    printf("    Variable Address : %p \n",&(LoverAbbr));
    printf("    Variable Hex Value : ");
    ShowBytes((BytePointer)&LoverAbbr, sizeof(LoverAbbr));

    printf("Case 5 : \n");
    printf("    Variable Type : Float \n");
    printf("    Variable Name : LoverBirthday \n");
    printf("    Variable Content : %f \n",LoverBirthday);
    printf("    Variable Address : %p \n",&(LoverBirthday));
    printf("    Variable Hex Value : ");
    ShowBytes((BytePointer)&LoverBirthday, sizeof(LoverBirthday));

    printf("Case 6 : \n");
    printf("    Variable Type : Double \n");
    printf("    Variable Name : LoverSpell \n");
    printf("    Variable Content : %lf \n",LoverSpell);
    printf("    Variable Address : %p \n",&(LoverSpell));
    printf("    Variable Hex Value : ");
    ShowBytes((BytePointer)&LoverSpell, sizeof(LoverSpell));

    printf("Case 7 : \n");
    printf("    Variable Type : Pointer \n");
    printf("    Variable Name : LoverAbbrPt \n");
    printf("    Variable Content : %x \n",LoverAbbrPt);
    printf("    Variable Address : %p \n",&LoverAbbrPt);
    printf("    Variable Hex Value : ");
    ShowBytes((BytePointer)&LoverAbbrPt, sizeof(LoverAbbrPt));

    printf("Case 8 : \n");
    printf("    Variable Type : Unsigned Int \n");
    printf("    Variable Name : LoveLimit \n");
    printf("    Variable Content : %u \n",LoveLimit);
    printf("    Variable Address : %p \n",&LoveLimit);
    printf("    Variable Hex Value : ");
    ShowBytes((BytePointer)&LoveLimit, sizeof(LoveLimit));

    printf("Case 9 : \n");
    printf("    Variable Type : Array \n");
    printf("    Variable Name : LoveBWH \n");
    printf("    Variable Content : %u \n",LoverBWH);
    printf("    Variable Address : %p \n",&LoverBWH);
    printf("    Variable Hex Value : ");
    ShowBytes((BytePointer)&LoverBWH, sizeof(LoverBWH));

    printf("Case 10 : \n");
    printf("    Variable Type : Array \n");
    printf("    Variable Name : LoveBWH \n");
    printf("    Variable Content : %u \n",LoverBWH);
    printf("    Variable Address : %p \n",&LoverBWH);
    printf("    Variable Hex Value : ");
    ShowBytes((BytePointer)&LoverBWH, sizeof(LoverBWH));


    printf("\n");
    return 0;
}
