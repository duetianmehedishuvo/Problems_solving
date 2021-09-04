/***

            Bismillahir Rahmanir Rahim
            Read in the name of Allah, who created you!!!
            Author : Mehedi Hasan Shuvo,
            Department of CSE, Dhaka University of Engineering & Technology,DUET.

***/
#include <iostream>
using namespace std;

#define ebar_khela_jombe_besh int main(void)
#define jitsen_bhai return 0

ebar_khela_jombe_besh
{
    string s1, s2, s3;
    int value1 = 0, value2 = 0, value3 = 0, value4 = 0;
    cin >> s1 >> s2 >> s3;
    string s4[3] = {s1, s2, s3};
    for (int i = 0; i < 3; i++)
    {
        if (s4[i] == "ABC")
        {
            value1 = 1;
        }
        else if (s4[i] == "ARC")
        {
            value2 = 1;
        }
        else if (s4[i] == "AGC")
        {
            value3 = 1;
        }
        else if (s4[i] == "AHC")
        {
            value4 = 1;
        }
    }
    if (value1 == 0 && value2 == 1 && value3 == 1 && value4 == 1)
    {
        cout << "ABC" << endl;
    }
    else if (value1 == 1 && value2 == 0 && value3 == 1 && value4 == 1)
    {
        cout << "ARC" << endl;
    }

    else if (value1 == 1 && value2 == 1 && value3 == 0 && value4 == 1)
    {
        cout << "AGC" << endl;
    }

    else if (value1 == 1 && value2 == 1 && value3 == 1 && value4 == 0)
    {
        cout << "AHC" << endl;
    }
    jitsen_bhai;
}