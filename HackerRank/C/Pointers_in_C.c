/***

            Bismillahir Rahmanir Rahim
            Read in the name of Allah, who created you!!!
            Author : Mehedi Hasan Shuvo,
            Department of CSE, Dhaka University of Engineering & Technology,DUET.

***/

#include<stdio.h>
#include <stdlib.h>
#define ebar_khela_jombe_besh    int main (void)
#define jitsen_bhai              return 0
#define  it int

void update(it *a,it *b){
    it c=*a,d=*b;
    *a=*a+*b;
    *b=abs(c-d);
}

ebar_khela_jombe_besh
{
    it a,b;
    scanf("%d %d",&a,&b);
    update(&a,&b);
    printf("%d\n%d",a,b);
    jitsen_bhai;
}