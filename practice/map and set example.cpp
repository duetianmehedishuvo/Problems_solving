#include<bits/stdc++.h>
using namespace std;
int main()
{

    map<string,int> ma;
    map<string,int>::iterator m;
    ma["Ni"]=1121;
    ma["Lo"]=1121;
    ma["Ni"]+=1;

    cout<<ma["Ni"]<<endl;
    m=ma.begin();
    ++m;
    cout<<m->first<<endl;
    for(m=ma.begin();m!=ma.end();++m){
        cout<<m->first<<" : "<<m->second<<endl;
    }
    cout<<endl<<endl;
    // example in set
    // set always get input unique
    set<int> sc;
    set<int>::iterator s;
    sc.insert(101);
    sc.insert(12);
    sc.insert(232);
    sc.insert(12);
    sc.insert(232);
    sc.insert(121);
    sc.insert(234232);
    sc.insert(1);
    sc.insert(4);

    cout<<sc.size()<<endl;
    for(s=sc.begin();s!=sc.end();++s){
        cout<<*s<<" ";
    }

    return 0;
}
