#include<bits/stdc++.h>
#include<vector>

using namespace std;
int main()
{

    vector<int> vcc;
    vector<int>::iterator v;
    vcc.push_back(6);
    vcc.push_back(32.90);
    vcc.push_back(34343);
    vcc.push_back(443);
    vcc.push_back(898876);
    vcc.push_back(7665);
    vcc.push_back(765);
    vcc.push_back(23232);
    vcc.push_back(56675);
    vcc.push_back(34354);

    cout<<vcc[0]<<endl;
    int length=vcc.size();
    cout<<length<<endl;
    v=vcc.begin();
    cout<<*v<<endl;

    for(int i=0; i<length; i++)
    {
        cout<<vcc[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    v=vcc.begin();
    advance(v,4);
    for(v; v!=vcc.end(); ++v)
    {
        cout<<*v<<endl;
    }

    cout<<endl;
    v=vcc.begin();
    advance(v,4);
    cout<<*v<<endl;
    cout<<endl;

    // for sort
    sort(vcc.begin(),vcc.end());
    for(int i=0; i<length; i++)
    {
        cout<<vcc[i]<<" ";
    }

    cout<<endl;
    cout<<endl;
    // for reverse
    reverse(vcc.begin(),vcc.end());
    for(int i=0; i<length; i++)
    {
        cout<<vcc[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    // other way for reverse
    sort(vcc.begin(),vcc.end(),greater<int>());
    for(int i=0; i<length; i++)
    {
        cout<<vcc[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<vcc.back()<<endl;
    cout<<vcc.front()<<endl;

    cout<<endl;
    cout<<endl;
    vcc.pop_back();
    vcc.pop_back();
    for(int i=0; i<length; i++)
    {
        cout<<vcc[i]<<" ";
    }

    cout<<endl;
    cout<<endl;
    vcc.clear();
    for(int i=0; i<length; i++)
    {
        cout<<vcc[i]<<" ";
    }
    cout<<endl;
    cout<<endl;

    vector<int> vec(5);
    vec.push_back(101);
    vec.push_back(101);
    vec.push_back(101);
    vec.push_back(101);
    vec.push_back(101);
    vec.push_back(101);
    vec.push_back(101);
    vec.push_back(101);
    vec.push_back(101);
    vec.push_back(101);
    vec.push_back(101);
    vec.push_back(101);
    cout<<vec.size()<<endl;
    cout<<endl;

    char str[]="Hello World";
    //memset(str,'P',7);
    memset(str,65,(sizeof(vcc)/2)-1);
    cout<<str;

    return 0;
}
