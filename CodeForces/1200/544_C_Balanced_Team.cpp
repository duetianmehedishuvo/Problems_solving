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

ebar_khela_jombe_besh
{
    int n;
    cin >> n;
    int a[200020], r = 1, ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        while (a[r] - a[i] <= 5 && r <= n)
        {
            r++;
        }
        ans = max(ans, r - i);
    }
    cout << ans << endl;
    jitsen_bhai;
}