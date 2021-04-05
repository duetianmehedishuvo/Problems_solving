#include<iostream>
using namespace std;

int main()
{
    long long n,d,x,y,ans=0;
    cin>>n>>d;
    while(n--){
        cin>>x>>y;
        if(x*x+y*y <=(d*d)) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
