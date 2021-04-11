#include<bits/stdc++.h>
using namespace std;

int findSmallestElement(int arr[], int n)
{
    int temp = arr[0];
    for(int i=0; i<n; i++)
    {
        if(temp>arr[i])
        {
            temp=arr[i];
        }
    }
    return temp;
}

int findLargestElement(int arr[], int n)
{
    int temp = arr[0];
    for(int i=0; i<n; i++)
    {
        if(temp<arr[i])
        {
            temp=arr[i];
        }
    }
    return temp;
}

int main()
{
    int T,n,i,j,c=1;
    cin>>T;
    long long N=1;
    for(i=1; i<=T; i++)
    {
        cin>>n;
        int Num[n];
        for(j=0; j<n; j++)
        {
            cin>>Num[j];
        }
        if(n==1)
        {
            N=Num[0]*Num[0];
        }
        else
        {
            N=findSmallestElement(Num,n)*findLargestElement(Num,n);
        }

        printf("Case %d: %lld\n",c,N);
        N=1;
        c++;
    }
    return 0;
}
