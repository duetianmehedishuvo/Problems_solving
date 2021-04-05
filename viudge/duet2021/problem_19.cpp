#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;

    if(s.size()>=t.size())
        for(int i=0; i<=s.size()-t.size(); i++)
            if(t==s.substr(i,t.size()))
                printf("%d\n",i);

    return 0;
}
