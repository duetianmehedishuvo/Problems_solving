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
#define llu unsigned long long
#define lld long long
#define U unsigned int

int max_of_four(int a, int b, int c, int d)
{
    return a > b && a > c && a > d ? a : b > c && b > d && b > a ? b
                                     : c > d && c > a && c > b   ? c
                                                                 : d;
}

ebar_khela_jombe_besh
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max_of_four(a, b, c, d) << endl;
    jitsen_bhai;
}