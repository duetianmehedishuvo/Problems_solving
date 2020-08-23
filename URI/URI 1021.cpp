#include <bits/stdc++.h>

using namespace std;

int main()
{
    double d;
    cin>>d;
    int n=d;
    int m=d*100;

    cout<<"NOTAS:"<<endl;
    cout<<n/100<<" nota(s) de R$ 100.00"<<endl;
    n=n%100;
    cout<<n/50<<" nota(s) de R$ 50.00"<<endl;
    n=n%50;
    cout<<n/20<<" nota(s) de R$ 20.00"<<endl;
    n=n%20;
    cout<<n/10<<" nota(s) de R$ 10.00"<<endl;
    n=n%10;
    cout<<n/5<<" nota(s) de R$ 5.00"<<endl;
    n=n%5;
    cout<<n/2<<" nota(s) de R$ 2.00"<<endl;
    n=n%2;
    cout<<"MOEDAS:"<<endl;
    cout<<n/1<<" moeda(s) de R$ 1.00"<<endl;
    m=m%100;
    cout<<m/50<<" moeda(s) de R$ 0.50"<<endl;
    m=m%50;
    cout<<m/25<<" moeda(s) de R$ 0.25"<<endl;
    m=m%25;
    cout<<m/10<<" moeda(s) de R$ 0.10"<<endl;
    m=m%10;
    cout<<m/5<<" moeda(s) de R$ 0.05"<<endl;
    m=m%5;
    cout<<m/1<<" moeda(s) de R$ 0.01"<<endl;


    return 0;
}
