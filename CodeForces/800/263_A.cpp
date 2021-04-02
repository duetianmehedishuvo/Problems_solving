#include<bits/stdc++.h>
using namespace std;
int main()
{

    int m,n,p;

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cin>>p;
            if(p==1)
            {
                m=i;
                n=j;
            }
        }
    }
    int sum1=abs(2-m);
    int sum2=abs(2-n);

    cout<<sum1+sum2<<endl;;
    return 0;
}
