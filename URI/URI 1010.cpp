#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d;
    double x,y;
    cin>>a>>b>>x>>c>>d>>y;
    cout<<"VALOR A PAGAR: R$ "<<fixed<<setprecision(2)<<(b*x)+(d*y)<<endl;
    return 0;
}
