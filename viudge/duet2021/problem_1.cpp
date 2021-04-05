#include<bits/stdc++.h>
using namespace std;
int main()
{

    int weight;
    cin>>weight;
    string status=(weight==2 || weight%2!=0)?"NO":"YES";
    cout<<status<<endl;

    return 0;
}
