#include <bits/stdc++.h>

using namespace std;

int main()
{

    double n[16],output=0;
    for(int i=0;i<6;i++){
        cin>>n[i];
    }
    for(int i=0;i<6;i++){
        if(n[i]>=0)
            output++;
    }
    cout<<output<<" valores positivos"<<endl;
    return 0;
}
