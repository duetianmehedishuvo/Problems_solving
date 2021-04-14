#include<bits/stdc++.h>
using namespace std;


// bigmod like (2^100)%5==1
int bigmod(int a,int b,int mod){
    if(b==0) return 1%mod;
    int x=bigmod(a,b/2,mod);
    x=(x*x)%mod;
    if(b&1) x=(x*a)%mod;
    return x;
}

// bigsum like a^0+a^1+a^2+a^3+a^4+a^5+a^6+a^7+a^8+a^9


int bigSum(int a,int b,int mod){
    if(b==0) return 1%mod;
    int x=bigSum((a*a)%mod,b/2,mod);
    x=(x+x)%mod;
    if(b&1) x=(x+a)%mod;
    return x;
}

int main(){

    cout<<bigmod(2,99,3)<<endl<<endl;
    cout<<bigSum(2,4,2)<<endl;

    return 0;
}