#include <iostream>
#include<string.h>

using namespace std;

int main()
{

    int i,n,e=0,o=0,p=0,ne=0;

    for(i=0;i<5;i++){
        cin>>n;

        if(n%2==0)
          e++;
        else
            o++;

        if(n>0)
            p++;
        else if(n<0)
            ne++;

    }
    cout<<e<<" valor(es) par(es)"<<endl;
    cout<<o<<" valor(es) impar(es)"<<endl;
    cout<<p<<" valor(es) positivo(s)"<<endl;
    cout<<ne<<" valor(es) negativo(s)"<<endl;

    return 0;
}
