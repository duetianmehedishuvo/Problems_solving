#include <iostream>
#include<string.h>

using namespace std;

int main()
{

    int i,n,l=0;

    for(i=0;i<5;i++){
        cin>>n;
        if(n%2==0)
          l++;

    }
    cout<<l<<" valores pares"<<endl;

    return 0;
}
