#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n,l=1;
    cin>>n;
    if(n>1 && n<1000){
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
            cout<<pow(i,2)<<" ";
            cout<<pow(i,3)<<endl;
        }
    }

    return 0;
}
