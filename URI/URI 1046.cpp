#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s,e;
    cin>>s>>e;
    if(s<=24 ||e<=24){

        if(s==0 && e==0)
            cout<<"O JOGO DUROU 24 HORA(S)"<<endl;
        else if(s>12){
            s=24-s;
            cout<<"O JOGO DUROU "<<s+e<<" HORA(S)"<<endl;
        }
        else{
            cout<<"O JOGO DUROU "<<e-s<<" HORA(S)"<<endl;
        }
    }


    return 0;
}
