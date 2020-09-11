#include <bits/stdc++.h>

using namespace std;

int main()
{

    int x,alcohol=0,gasoline=0,diesel=0;
    while(1){
        cin>>x;
        if(x==1 ||x==2 || x==3 || x==4){
            if(x==1) alcohol++;
            else if(x==2) gasoline++;
            else if(x==3) diesel++;
            else if(x==4) break;
        }

    }

    cout<<"MUITO OBRIGADO"<<endl;
    cout<<"Alcool: "<<alcohol<<endl;
    cout<<"Gasolina: "<<gasoline<<endl;
    cout<<"Diesel: "<<diesel<<endl;


    return 0;
}
