#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y,z,result;
    cin>>x>>y>>z;
    if(x==z) result=y-1;
    else {
        result=((y*z)-(33.0/61079.0))/x;
    }

    cout<<result<<endl;

    return 0;
}