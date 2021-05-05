#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,count=0,temp;
    cin>>t;
    while (t--)
    {
        
        scanf("%d",&n);
        count=0;
        while (n>0)
        {
           temp=n%10;
           if(temp==4) count++;
           n=n/10;
        }
        cout<<count<<endl;
        
    }
    
    return 0;
}