#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    
    for(int c=b;;c--){
        if(((a+c-1)/c)<(b/c)){
           cout<<c<<endl;
            return  0; 
        } 
    }
    return 0;
}