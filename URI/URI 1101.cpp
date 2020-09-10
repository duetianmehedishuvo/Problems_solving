#include <bits/stdc++.h>

using namespace std;

int main()
{

    int x,y;
    while(1){
        cin>>x>>y;
        int sum=0;
        if(x>0 && y>0){
            if(x>=y)
            {
                for(int i=y;i<=x;i++){
                    sum+=i;
                    cout<<i<<" ";
                }
                cout<<"Sum="<<sum<<endl;
            }
        else if(x<=y)
            {
                for(int i=x;i<=y;i++){
                    sum+=i;
                    cout<<i<<" ";
                }
                cout<<"Sum="<<sum<<endl;
            }
        }else
            break;

    }

    return 0;
}
