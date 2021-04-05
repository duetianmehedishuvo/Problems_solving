#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,t,n,k,m,data;
    cin>>t;
    vector<int> vec;
    while(t--)
    {
        cin>>n>>k;
        for(i=0; i<n; i++)
        {
            scanf("%d",&data);
            vec.push_back(data);
        }
        m=0;
        for(i=0; i<n; i++)
        {
            if(vec[i]<vec[k-1]) m++;
        }
        cout<<m+1<<'\n';
        vec.clear();
    }
    return 0;
}
