#include <iostream>
#include<string.h>

using namespace std;

int main()
{

    int n,i,j=0;
    cin>>n;
    for(i=1;i<n;i++){
        if(n%i==0){
            j++;
        }
    }
    cout<<j<<endl;

    return 0;
}
