#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a,b,c,x1,x2,d;
    cin>>a>>b>>c;
    d=(b*b)-(4*a*c);
    if(d>0&& a!=0){
        x1=(-b+sqrt(d))/(2*a);
        x2=(-b-sqrt(d))/(2*a);
        cout<<"R1 = "<<fixed<<setprecision(5)<<x1<<endl;
        cout<<"R2 = "<<fixed<<setprecision(5)<<x2<<endl;
    }else{
        cout<<"Impossivel calcular"<<endl;
    }

    return 0;
}
