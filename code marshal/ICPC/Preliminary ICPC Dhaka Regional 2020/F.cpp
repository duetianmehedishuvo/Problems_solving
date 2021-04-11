#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t,count=0;
    int a,b,m;
    cin>>t;
    if(t>=1 && t<=1000)
    {
        for(int i=1; i<=t; i++)
        {
            scanf("%d%d%d",&a,&b,&m);
            for(int j=0; j<=m; j++)
            {
                if(__gcd(a+j,b+j)==1) count++;

            }
            printf("Case %d: %d\n",i,count);
            count=0;

        }
    }

    return 0;
}
