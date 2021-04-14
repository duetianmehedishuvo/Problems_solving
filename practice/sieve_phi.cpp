// Euler's Totient Function

#include<bits/stdc++.h>
using namespace std;
int phi[1000006],mark[1000006];
// sieve phi for every digit like user give 20 then do 1 to 20 
//and find co-prime. co-prime means whos number isn't any releted of n.
void sievePhi(int n){
    int i,j;

    // initialization
    for(i=1;i<=n;i++) phi[i]=i;
    phi[1]=1;
    mark[1]=1;
    for(i=2;i<=n;i++){
        if(!mark[i]){
            for(j=i;j<=n;j+=i){
                mark[j]=1;
                // phi[j] will be divisible by i
                // so no need to worry
                phi[j]=phi[j]/i*(i-1);
            }
        }
        cout<<'\n';
    }
}

// loop phi find specific n number co-prime count
int loopPhi(int n){
    int ret=n;
    for(int i=2;i<=n;i++){
        if(n%i==0){
            // i is prime dividing n
            while(n%i==0){
                // dividing all factor of i
                n=n/i;
            }
            ret=ret-(ret/i);
        }
    }
    if(n>1){
        // there can be only one prime greater
        // than sqrt(n) that divides n
        ret=ret-(ret/n);
    }
    return ret;

}

int main(){
    sievePhi(10);
    cout<<loopPhi(22);

    return 0;
}