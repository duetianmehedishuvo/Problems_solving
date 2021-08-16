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


ebar_khela_jombe_besh
{
    it n,sum=0;
    scanf("%d",&n);
    while(n>0){
        sum+=n%10;
        n=n/10;
    }
    printf("%d",sum);
    jitsen_bhai;
}