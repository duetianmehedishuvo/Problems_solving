#include<bits/stdc++.h>
using namespace std;

int count(int a[],int m,int n){
    int odd=0,even=0;
    int counter,i,j,p=1;
    //left shift operator
    int pow_set_size=(1<<n);

    // Run from counter 0000.0000 to 111.1111
    for(counter=1;counter<pow_set_size;counter++){
        p=1;
        for(j=0;j<n;j++){
            // check if jth bit in the counter is set if set then pront jth element from set
            //cout<< (1<<j)<<endl;
            if(counter & (1<<j)){
                //cout<<"counter: "<<counter<<" P is: "<<p<<" J is: "<<j<<" J Binary: "<<(1<<j)<<" A[j]: "<<a[j]<<endl;
                p=p*a[j];
            }
        }
        //cout<<endl;

        // if set bits is odd,then add to the number of multiples
        //cout<<"Counter: "<<counter<<" Binary Number: "<<__builtin_popcount(counter)<<" M is: "<<m<<" P is: "<<p<<endl; 
        if(__builtin_popcount(counter) &1) {
            odd+=(m/p);
        }else{
            even+=(m/p);
        }
    }

    return odd-even;
}
int main(){

    int a[]={2,3,5,7};
    int m=100;
    int n=sizeof(a)/sizeof(a[0]);
    cout<<count(a,m,n);
    return 0;
}