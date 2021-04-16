#include<bits/stdc++.h>
using namespace std;
int modInverse(int a,int m){

    int one,two,result;

    for(int x=1;x<m;x++){
        one=a%m;
        two=x%m;
        result=(one*two)%m;

        if(result ==1) return x;
    }
    return -1;
}
int main(){

int a=3,m=11;
cout<<modInverse(a,m)<<endl;

    return 0;
}