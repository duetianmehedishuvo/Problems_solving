/***

            Bismillahir Rahmanir Rahim
            Read in the name of Allah, who created you!!!
            Author : Mehedi Hasan Shuvo,
            Department of CSE, Dhaka University of Engineering & Technology,DUET.

***/

#include<stdio.h>
#define ebar_khela_jombe_besh    int main (void)
#define jitsen_bhai              return 0
#define it int

ebar_khela_jombe_besh
{
    int n,i,j;
    scanf("%d",&n);

    // first upper half of the pattern
    for(i=n;i>=1;i--){
        // first inner part of upper half
        for(j=n;j>i;j--){
            printf("%d ",j);
        }
        // second inner part of upper half
        for(j=1;j<=(i*2-1);j++){
            printf("%d ",i);
        }

        // third inner part of upper half
        for(j=i+1;j<=n;j++){
            printf("%d ",j);
        }
        printf("\n");
    }

    // second lower half of the pattern

    for(i=1;i<n;i++){
        // first inner part of upper half
        for(j=n;j>i;j--){
            printf("%d ",j);
        }
        // second inner part of upper half
        for(j=1;j<=(i*2-1);j++){
            printf("%d ",i+1);
        }

        // third inner part of upper half
        for(j=i+1;j<=n;j++){
            printf("%d ",j);
        }
        printf("\n");
    }

    jitsen_bhai;
}
