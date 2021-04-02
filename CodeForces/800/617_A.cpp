#include<bits/stdc++.h>
using namespace std;
int main()
{

    int x,i=1,sum=0;
    cin>>x;
    if(x%5==0) sum=x/5;
    else sum=x/5+1;
    cout<<sum<<endl;

    return 0;
}
