#include <bits/stdc++.h>

using namespace std;

int main()
{

    float n[16],output=0,avg,count=0;
    for(int i=0;i<6;i++){
        cin>>n[i];
    }
    for(int i=0;i<6;i++){
        if(n[i]>=0){
            output++;
            count=count+n[i];
        }

    }
    avg=count/output;
    cout<<output<<" valores positivos"<<endl;
    cout<<fixed<<setprecision(1)<<avg<<endl;
    return 0;
}
