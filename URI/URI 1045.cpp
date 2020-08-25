#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a,b,c,d,e,f;
    cin>>a>>b>>c;
    d=a*a;
    e=b*b;
    f=c*c;
    if(a>=(b+c) || b>=(a+c) || c>=(a+b))
        cout<<"NAO FORMA TRIANGULO"<<endl;
    else if(d==(e+f) || e==(d+f) || f==(d+e))
        cout<<"TRIANGULO RETANGULO"<<endl;
    else if(d>(e+f) || e>(d+f) || f>(d+e))
        cout<<"TRIANGULO OBTUSANGULO"<<endl;
    else if(d<(e+f) || e<(d+f) || f<(d+e))
        cout<<"TRIANGULO ACUTANGULO"<<endl;

    if(a==b && b==c)
        cout<<"TRIANGULO EQUILATERO"<<endl;
    else if((a==b&&a!=c) || (a==c&&a!=b) ||(b==c &&b!=a))
        cout<<"TRIANGULO ISOSCELES"<<endl;

    return 0;
}
