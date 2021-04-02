#include<bits/stdc++.h>
using namespace std;
int main()
{

    int k,n,w,sum=0,status=1;
    cin>>k>>n>>w;
    for(int i=0; i<w; i++)
    {
        sum+=(k*status);
        status++;
    }
    if((n-sum)>=0) cout<<"0"<<endl;
    else cout<<sum-n<<endl;
    return 0;
}
