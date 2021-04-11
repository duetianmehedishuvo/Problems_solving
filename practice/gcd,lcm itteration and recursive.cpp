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
    a=tempA;
    b=tempB;
    cout<<"GCD using Recursive Function: "<<a<<","<<b<<"="<<gcd(a,b)<<endl<<endl;

    // LCM Example
    a=tempA;
    b=tempB;
    cout<<"LCM Of: "<<tempA<<","<<tempB<<"="<<((a*b)/(gcd(a,b)))<<endl;

    return 0;
}
