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
    string s;
    bool flag = false;
    cin >> s;
    int n = s.length();
    int i = 0;
    while (i < n)

    {
        if (s[i] >= 33 && s[i] <= 126)
        {
            if (s[i] == 'H' || s[i] == 'Q'|| s[i] == '9')
            {
                flag = true;
            }
        }

        i++;
    }

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    jitsen_bhai;
}
