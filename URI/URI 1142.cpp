#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n,l=1;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=l;j<(l+3);j++){
            cout<<j<<" ";
        }
        cout<<"PUM"<<endl;
        l+=4;
    }

    return 0;
}
