#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a,b,c,d,e,avg;
    cin>>a>>b>>c>>d;
    avg=(a*2+b*3+c*4+d*1)/(2+3+4+1);
    cout<<"Media: "<<fixed<<setprecision(1)<<avg<<endl;
    if(avg>7.0)
        cout<<"Aluno aprovado."<<endl;
    else if(avg<5.0)
        cout<<"Aluno reprovado."<<endl;
    else if(avg>=5.00&&avg<=6.9){
        cout<<"Aluno em exame."<<endl;
        cin>>e;
        cout<<"Nota do exame: "<<e<<endl;
        avg=(avg+e)/2;
        if(avg>5.0)
            cout<<"Aluno aprovado."<<endl;
        else
            cout<<"Aluno reprovado."<<endl;
            cout<<"Media final: "<<fixed<<setprecision(1)<<avg<<endl;

    }

    return 0;
}
