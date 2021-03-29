#include<iostream>
using namespace std;
int main()
{

    int n,k,sum=0,num[50];
    cin>>n>>k;
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    for(int i=0;i<n;i++) {
     if(num[i]>=num[k-1] && num[i]>0) sum++;
    }

    cout<<sum<<endl;
    return 0;
}
