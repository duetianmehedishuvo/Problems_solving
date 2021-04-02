#include<bits/stdc++.h>
using namespace std;
int main()
{

    int a,b,year=0;
    cin>>a>>b;
    while(true)
    {
        if(a>b) break;
        year++;
        a=a*3;
        b=b*2;
    }
    cout<<year<<endl;
    return 0;
}
