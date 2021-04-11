#include<bits/stdc++.h>
using namespace std;

int minswaps(long int arr[],int n)
{
    int i;
    pair<int,int> arrpos[n];
    for(i=0; i<n; i++)
    {
        arrpos[i].first=arr[i];
        arrpos[i].second=i;
    }
    sort(arrpos,arrpos+n);
    vector<bool> isVisited(n,false);
    int ans=0;
    for(i=0; i<n; i++)
    {
        if(isVisited[i] || arrpos[i].second==i) continue;

        int cycle_size=0;
        int j=i;
        while(!isVisited[j])
        {
            isVisited[j]=1;
            j=arrpos[j].second;
            cycle_size++;
        }
        if(cycle_size>0) ans+=(cycle_size-1);
    }
    return ans;
}


int main()
{

    int testCase;
    cin>>testCase;
    int n,i,j;
    int sum=0;
    for(j=1; j<=testCase; j++)
    {

        scanf("%d",&n);
        long int arr[n];
        for(i=0; i<n; i++)
        {
            scanf("%ld",&arr[i]);
            if(arr[i]>=0) sum+=arr[i];
        }
        int p=minswaps(arr,n-1);

        printf("Case %d: %d %d\n",j,sum,p);
        sum=0;
    }

    return 0;
}
