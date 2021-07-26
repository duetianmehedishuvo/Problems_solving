/*
Name: Mehedi Hasan Shuvo
Problem No: 41A
Problem Title: Translation
Status: Accepted 
*/

#include <iostream>
#include<string>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int flag = 0, length1 = 0, length2 = 0;
    length1 = s1.length();
    length2 = s2.length();

    for (int i = 0; i < length1; i++)
    {
        if (s1[i] != s2[length2 - 1])
        {
            flag = 1;
            break;
        }
        length2--;
    }
    if (flag == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}