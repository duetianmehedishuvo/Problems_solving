#include <iostream>
#include<string.h>

using namespace std;

int main()
{

    int i,n;
    cin>>n;
    if(n>=1 && n<= 1000){
        for(i=1;i<=n;i++){
            if(i%2!=0)
                cout<<i<<endl;
        }
    }

    return 0;
}
