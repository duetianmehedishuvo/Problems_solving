#include <iostream>
#include<string.h>

using namespace std;

int main()
{

    int n,i;
    cin>>n;
    if(n>5 && n<2000){
        for(i=2;i<=n;i+=2){
            cout<<i<<"^2 = "<<(i*i)<<endl;
        }
    }

    return 0;
}
