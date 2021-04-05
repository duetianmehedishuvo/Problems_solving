#include<bits/stdc++.h>
#define ll long long
typedef long long li;
const long long lim=100;
const long long lii=(int) 1e5;


using namespace std;
struct Information{
    int id;
    string name;
    float gpa;

}In;
int main()
{
    pair<int,int> pa;
    //cin>>pa.first>>pa.second;
    pa=make_pair(10,20);
    cout<<pa.first<<" "<<pa.second<<endl;


    ll data;
    //cin>>data;
    cout<<lii<<endl;

    struct Information in;
    cin>>in.id;

    cin.ignore();
    getline(cin,in.name);

    cin>>in.gpa;

    cout<<in.id<<" "<<in.name<<" "<<in.gpa<<endl;

    return 0;
}
