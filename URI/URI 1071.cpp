#include <iostream>
#include<string.h>

using namespace std;

int main()
{

    int i,m,n,sum=0;
    int min,max;
    cin>>m;
    cin>>n;
    if(m<n){
        min=m;
        max=n;
    }else{
        min=n;
        max=m;
    }

    for(i=(min+1);i<max;++i){

        if(i%2!=0)
        sum+=i;
    }
    cout<<sum<<endl;


    return 0;
}
