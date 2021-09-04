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

llu valueReturn(int temp)
{
    llu value = 0;
    if (temp == 0)
    {
        value = 6;
    }
    else if (temp == 1)
    {
        value = 2;
    }
    else if (temp == 2)
    {

        value = 5;
    }
    else if (temp == 3)
    {
        value = 5;
    }
    else if (temp == 4)
    {
        value = 4;
    }
    else if (temp == 5)
    {
        value = 5;
    }
    else if (temp == 6)
    {
        value = 6;
    }
    else if (temp == 7)
    {
        value = 3;
    }
    else if (temp == 8)
    {
        value = 7;
    }
    else if (temp == 9)
    {
        value = 6;
    }
    return value;
}

ebar_khela_jombe_besh
{

    llu a, b, sum = 0;
    cin >> a >> b;
    for (llu i = a; i <= b; i++)
    {
        llu temp = i;
        while (temp != 0)
        {
            int temp_value = temp % 10;
            sum += valueReturn(temp_value);
            temp /= 10;
        }
    }
    cout << sum << endl;
    jitsen_bhai;
}