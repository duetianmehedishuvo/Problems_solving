#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    vector<string> data1(n),data2(n);
    for(i=0; i<n; i++)
    {
        cin>>data1[i];
        data2[i]=data1[i];
    }

    // for bubble sort
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(data1[j][1]>data1[j+1][1])
            {
                swap(data1[j],data1[j+1]);
            }
        }
    }
    for(i=0; i<n; i++) cout<<(i!=0?" ":"")<<data1[i];
    cout<<endl<<"Stable"<<endl;

    // for Selection Sort
    for(i=0; i<n; i++)
    {
        int mini=i;
        for(j=i+1; j<n; j++)
        {
            if(data2[j][1]<data2[mini][1]) mini=j;
        }
        if(mini!=i) swap(data2[i],data2[mini]);
    }
    for(i=0; i<n; i++) cout<<(i!=0?" ":"")<<data2[i];
    if(data1==data2) cout<<endl<<"Stable"<<endl;
    else cout<<endl<<"Not stable"<<endl;

    return 0;
}
