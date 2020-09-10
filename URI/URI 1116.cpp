#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin>>n;
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        if(y==0)
            cout<<"divisao impossivel"<<endl;
        else{
            double z=(double)x/(double)y;
           cout<<fixed<<setprecision(1)<<z<<endl;
        }

    }


    return 0;
}
