#include<bits/stdc++.h>
using namespace std;
int main()
{
    char data[200];
    vector<string> data1;
    vector<string>::iterator data2;
    while(scanf("%s",data)!=EOF)
    {
        data1.push_back(data);
    }
    cout<<data1;

    for(data2=data1.begin();data2!=data1.end();++data2){
        //cout<<data2<<endl;
    }

    return 0;
}
