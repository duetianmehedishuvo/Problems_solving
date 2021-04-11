#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a[100],i,pos=-1,data;
    cin>>t;
    while (t--)
    { 
        cin>>n;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        data=a[0];
        if(a[0] != a[n-1])
        {
            if((a[1] !=a[n-1]))
            {
                pos=n-1;
            }else{
               pos=0;
            }
        }
        else
        {
            for(i=0; i<n-1; i++)
            {
                for(int j=i+1; j<n; j++)
                {
                    if(a[i]!=a[j])
                    {
                        pos=i;
                    }
                }
            }
        }

        cout<<pos+1<<endl;

    }

    return 0;
}
