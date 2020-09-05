#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n,i,l=0,highest=-1;
    for(i=1;i<=100;i++){
        cin>>n;
        if(highest<n){
           highest= n;
           l=i;
        }
    }
    cout<<highest<<endl;
    cout<<l<<endl;

    return 0;
}
