/***

            Bismillahir Rahmanir Rahim
            Read in the name of Allah, who created you!!!
            Author : Mehedi Hasan Shuvo,
            Department of CSE, Dhaka University of Engineering & Technology,DUET.

***/
#include <bits/stdc++.h>
using namespace std;

#define ebar_khela_jombe_besh int main(void)
#define jitsen_bhai return 0
#define u unsigned int

ebar_khela_jombe_besh
{

    u n, sum = 0, i, p, q;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> p >> q;
        if (q -p >1)
            sum++;
    }
    cout << sum << endl;
    jitsen_bhai;
}