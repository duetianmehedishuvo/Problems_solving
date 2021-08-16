/***

            Bismillahir Rahmanir Rahim
            Read in the name of Allah, who created you!!!
            Author : Mehedi Hasan Shuvo,
            Department of CSE, Dhaka University of Engineering & Technology,DUET.

***/
#include <stdio.h>
#define ebar_khela_jombe_besh int main(void)
#define jitsen_bhai return 0
#define max(a, b) ((a) > (b) ? (a) : (b))
#define it int

void calculate_the_maximum(int n, int k)
{
    it maxAnd = 0, maxOr = 0, maxXor = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if ((i & j) < k)
                maxAnd = max(maxAnd, (i & j));

            if ((i | j) < k)
                maxOr = max(maxOr, (i | j));

            if ((i ^ j) < k)
                maxXor = max(maxXor, (i ^ j));
        }
    }
    printf("%d\n%d\n%d", maxAnd, maxOr, maxXor);
}

ebar_khela_jombe_besh
{
    it n, k;
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
    jitsen_bhai;
}
