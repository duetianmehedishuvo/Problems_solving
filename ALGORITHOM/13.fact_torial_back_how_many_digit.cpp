#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,m,sum=0,x,divisor_value=1;
    cout<<"Enter The Facetorial: ";
    cin>>n;
    cout<<"Enter the number do you want: ";
    cin>>m;
    if(m==0){
        x=5;
    }
    
    while (divisor_value !=0)
    {
        if(m==0){
            
            divisor_value=n/x;
            sum+=divisor_value;
            x=x*x;
        }else{
            divisor_value=n/m;
            sum+=divisor_value;
            m=m*m;
        }
    }

    cout<<sum<<endl;
    
    return 0;
}