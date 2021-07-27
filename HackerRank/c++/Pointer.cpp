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

void update(int &a, int &b)
{
    int c = a;
    int d = b;
    a = c + d;
    b = c - d;
}

ebar_khela_jombe_besh
{
    int a, b;
    cin >> a >> b;
    update(a, b);
    cout << a << "\n"
         << abs(b) << endl;

    jitsen_bhai;
}