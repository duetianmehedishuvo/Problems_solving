#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1;
    char rem[100];
    int j=0;
    cin>>str1;
    for(int i=0; i<str1.size(); i++)
    {
        if(str1[i]!='+')
        {
            rem[j]=str1[i];
            j++;
        }
    }
    sort(rem, rem+j);
    for (int i = 0; i < j; i++)
    {
        if (i == j - 1) cout << rem[i] << endl;
        else cout << rem[i] << "+";
    }
    return 0;
}
