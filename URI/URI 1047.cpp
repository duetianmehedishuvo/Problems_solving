#include <bits/stdc++.h>

using namespace std;

int main()
{
    int fh,fm,lh,lm,m=0,h=0;
    cin>>fh>>fm>>lh>>lm;

    if(fh<=24 || fm <=60 || lh<=24 || lm<=60){
        if(fm>lm){
            lm=lm+60;
            fh+=1;
        }
        m=lm-fm;
        if(fh>lh){
            h=24-(fh-lh);
            cout<<"O JOGO DUROU "<<h<<" HORA(S) E "<<m<<" MINUTO(S)"<<endl;
        }else if(fh==lh && fm==lm)
            cout<<"O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)"<<endl;
        else{
            h=lh-fh;
            cout<<"O JOGO DUROU "<<h<<" HORA(S) E "<<m<<" MINUTO(S)"<<endl;
        }
    }

    return 0;
}
