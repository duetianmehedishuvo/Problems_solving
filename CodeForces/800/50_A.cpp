#include<iostream>
using namespace std;
int main()
{
    int m,n,sum=0,i;
    cin>>m>>n;
    for(i=2; i<=m*n; i+=2)sum++;
    cout<<sum<<endl;

    return 0;
}
