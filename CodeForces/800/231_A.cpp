#include<iostream>
using namespace std;
int main()
{
    int n,a,b,c,sum=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if((a+b+c)>1) sum++;
    }
    cout<<sum<<endl;

    return 0;
}
