#include <bits/stdc++.h>

using namespace std;

int main()
{
    char ch[30];
    cin>>ch;
    double a,b;
    cin>>a>>b;
    cout<<"TOTAL = R$ "<<fixed<<setprecision(2)<<(b*0.15)+a<<endl;
    return 0;
}
