#include<bits/stdc++.h>
using namespace std;
int main()
{

    string st1,st2;
    cin>>st1>>st2;
    for(auto& c : st1) c = tolower(c);
    for(auto& c : st2) c = tolower(c);

    if(st1>st2) cout<<"1"<<endl;
    else if(st1<st2) cout<<"-1"<<endl;
    else if(st1==st2) cout<<"0"<<endl;


    return 0;
}

