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

ebar_khela_jombe_besh
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        b[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }
    cout << '\n';
    jitsen_bhai;
}