#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,s,m,h;
    cin>>n;
    s=n%60;
    n=n/60;
    h=n/60;
    m=n%60;
    cout<<h<<":"<<m<<":"<<s<<endl;
    return 0;
}
