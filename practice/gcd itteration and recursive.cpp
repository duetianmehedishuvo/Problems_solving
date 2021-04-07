#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{

    int a=36,b=60;
    int tempA=a,tempB=b;
    while(a!=b)
    {
        if(a>b) a-=b;
        else b-=a;
    }
    cout<<"GCD using While Loop: "<<tempA<<","<<tempB<<"="<<a<<endl<<endl;
    a=36;
    b=60;
    cout<<"GCD using Recursive Function: "<<a<<","<<b<<"="<<gcd(a,b)<<endl<<endl;

    return 0;
}
