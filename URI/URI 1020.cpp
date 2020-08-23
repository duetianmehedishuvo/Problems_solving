#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,y,m,d;
    cin>>n;
    y=n/365;
    n=n%365;
    m=n/30;
    d=n%30;
    cout<<y<<" ano(s)"<<endl;
    cout<<m<<" mes(es)"<<endl;
    cout<<d<<" dia(s)"<<endl;
    return 0;
}
