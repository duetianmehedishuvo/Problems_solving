#include<bits/stdc++.h>
using namespace std;
/*
int max(int,int);
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
float max(float a,float b)
{
    if(a>b) return a;
    return b;
}
*/

template<typename x,typename y>
x max1(x a,y b)
{
    if(a>b) return a;
    return b;
}

int main()
{

/*
    int a,b,c,d,e;
    a=10;
    b=20;
    c=30;
    d=40;
    e=50;
    cout<<min({a,b,c,d,e})<<endl;
    cout<<max({a,b,c,d,e})<<endl;
    */

    cout<<max1(5,7)<<endl;
    cout<<max1(3.223,3.220)<<endl;
    cout<<max1(302,121)<<endl;
    cout<<max1<int>(12.231,32.12)<<endl;

    return 0;
}
