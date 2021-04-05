#include<bits/stdc++.h>
using namespace std;
int main()
{

    string text;
    int caseStatus=0;
    while(true)
    {
        cin>>text;
        if(text=="*") return 0;
        cout<<"Case "<<++caseStatus<<": ";
        if(text=="Hajj") cout<<"Hajj-e-Akbar"<<endl;
        else if(text=="Umrah") cout<<"Hajj-e-Asghar"<<endl;
    }
    return 0;
}
