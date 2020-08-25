#include <bits/stdc++.h>

using namespace std;

int main()
{
    double n,increase=0,totalSallery=0;
    int percent;
    cin>>n;
    if(n>=0 && n<=400.00){
        totalSallery=n+((n*15)/100);
        increase=((n*15)/100);
        percent=15;
    }else if(n>=400.01 && n<=800.00){
        totalSallery=n+((n*12)/100);
        increase=((n*12)/100);
        percent=12;
    }else if(n>=800.01 && n<=1200.00){
        totalSallery=n+((n*10)/100);
        increase=((n*10)/100);
        percent=10;
    }else if(n>=1200.01 && n<=2000.00){
        totalSallery=n+((n*7)/100);
        increase=((n*7)/100);
        percent=7;
    }else{
        totalSallery=n+((n*4)/100);
        increase=((n*4)/100);
        percent=4;
    }
    cout<<"Novo salario: "<<fixed<<setprecision(2)<<totalSallery<<endl;
    cout<<"Reajuste ganho: "<<fixed<<setprecision(2)<<increase<<endl;
    cout<<"Em percentual: "<<percent<<" %"<<endl;
    return 0;
}
