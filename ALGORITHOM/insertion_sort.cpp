#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,num[10],x,j;
    cout<<"How many number do you want?"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<n;i++){
        x=num[i];
        j=i-1;
        while(j>=0&& num[j]>x){
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=x;
    }
    for(int i=0;i<n;i++)
        cout<<num[i]<<" ";
	return 0;
}
