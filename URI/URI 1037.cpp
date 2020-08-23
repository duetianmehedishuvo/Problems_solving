#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x;
    cin>>x;
    int a=x;
    if(x>=0.00 && x<=25.00){
        cout<<"Intervalo [0,25]"<<endl;
    }else if(x>=25.00001 && x<=50.00){
        cout<<"Intervalo (25,50]"<<endl;
    }else if(x>=50.00001 && x<=75.00){
        cout<<"Intervalo (50,75]"<<endl;
    }else if(x>=75.00001 && x<=100.00){
        cout<<"Intervalo (75,100]"<<endl;
    }else{
        cout<<"Fora de intervalo"<<endl;
    }

    return 0;
}
