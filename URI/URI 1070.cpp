#include <iostream>
#include<string.h>

using namespace std;

int main()
{

    int i,n;
    cin>>n;
    if(n>0){
        for(i=n;i<n+12;i++){
            if(i%2!=0)
            cout<<i<<endl;

        }
    }

    return 0;
}
