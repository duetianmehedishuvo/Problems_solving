#include<bits/stdc++.h>
using namespace std;
int main()
{
    string name;
    cin>>name;
    sort(name.begin(),name.end());
    auto res=unique(name.begin(),name.end());
    string nameTwo=string(name.begin(), res);

    if(((nameTwo.size())%2)==0) cout<<"CHAT WITH HER!"<<endl;
    else cout<<"IGNORE HIM!"<<endl;

    return 0;
}
