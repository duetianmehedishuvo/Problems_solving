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
    u n;
    cin >> n;
    u a[n + 1], b[n + 1];
    for (u i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (u i = 1; i <= n; i++)
    {
        b[a[i]] = i;
    }
    for (u i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    jitsen_bhai;
}