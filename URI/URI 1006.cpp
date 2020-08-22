#include <bits/stdc++.h>

using namespace std;

int main()
{
    float a,b,c,med;
    cin>>a>>b>>c;
    med=((a*2)+(b*3)+(c*5))/(2+3+5);
    cout<<"MEDIA = "<<fixed<<setprecision(1)<<med<<endl;
    return 0;
}
