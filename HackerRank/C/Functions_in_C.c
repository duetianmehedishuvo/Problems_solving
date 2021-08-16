/***

            Bismillahir Rahmanir Rahim
            Read in the name of Allah, who created you!!!
            Author : Mehedi Hasan Shuvo,
            Department of CSE, Dhaka University of Engineering & Technology,DUET.

***/

#include <stdio.h>
#define ebar_khela_jombe_besh int main(void)
#define jitsen_bhai return 0
#define it int
#define max(x, y) (((x) > (y)) ? (x) : (y))

it max_of_four(it a, it b, it c, it d)
{

    return max(max(a, b), max(c, d));
}

ebar_khela_jombe_besh
{
    it a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    it ans = max_of_four(a, b, c, d);
    printf("%d", ans);

    jitsen_bhai;
}