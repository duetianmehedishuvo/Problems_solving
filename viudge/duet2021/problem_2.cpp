#include<bits/stdc++.h>
using namespace std;
int main()
{

    string str1;
    string str2;
    cin>>str1>>str2;
    for(auto& c : str1){c = tolower(c);}
    for(auto& c : str2){c = tolower(c);}
    if((str1.compare(str2)) == 0) cout<<"0"<<endl;
    else if((str1.compare(str2)) < 0) cout<<"-1"<<endl;
    else  cout<<"1"<<endl;

    return 0;
}
