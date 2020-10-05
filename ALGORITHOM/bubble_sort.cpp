#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,num[10],temp;
    cout<<"How many number do you want?"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(num[j+1]<num[j]){
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;

            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<num[i]<<" ";
	return 0;
}
