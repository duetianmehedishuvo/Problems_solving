#include<bits/stdc++.h>
using namespace std;

//Program for nth Catalan Number

unsigned long int catalanNumber(unsigned  int n){
    // base case
    if(n<=1) return 1;
    unsigned long int result=0;
    for(int i=0;i<n;i++){
        result+=catalanNumber(i)*catalanNumber(n-i-1);
    }
    return result;
}

int main(){

    for(int i=0;i<=10;i++){
        cout<<"CataLan Number for Index: "<<i<<" = "<<catalanNumber(i)<<endl;
    }

    return 0;
}