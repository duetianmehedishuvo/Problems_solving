#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,result=0;
    string testConst;
    cin>>n;
    while(n--)
    {
        cin>>testConst;

        if(testConst=="++X" ||testConst=="X++") ++result;
        else if(testConst=="--X"||testConst=="X--") --result;
    }

    cout<<result<<endl;

    return 0;
}
