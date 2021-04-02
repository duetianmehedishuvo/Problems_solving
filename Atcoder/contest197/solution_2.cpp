#include<bits/stdc++.h>

using namespace std;
int main()
{

    int h,v,x,y,i;
    cin>>h>>v>>x>>y;
    --x;
    --y;
    vector<string> s(h);
    for(i=0;i<h;i++) cin>>s[i];
    int result=0;

    for(i=y;i<v;i++){
        if(s[x][i]=='.') result++;
        else break;
    }
    for(i=y;i>=0;i--){
        if(s[x][i]=='.') result++;
        else break;
    }
    for(i=x;i<h;i++){
        if(s[i][y]=='.') result++;
        else break;
    }
    for(i=x;i>=0;i--){
        if(s[i][y]=='.') result++;
        else break;
    }
    cout<<result-3;

    return 0;
}
