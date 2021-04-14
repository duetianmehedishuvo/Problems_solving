#include<iostream>
using namespace std;

int seive(int n){
    int ret=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while (n%i==0)
            {
                n/=i;
            }
            ret=ret-(ret/i);
        }
    }
    if(n>1){
        ret=ret-(ret/n);
    }
    return ret;
}

int main(){
    int t,n;
    cin>>t;
    while (t--)
    {
        scanf("%d",&n);
        cout<<seive(n)<<'\n';
    }
    

    return 0;
}