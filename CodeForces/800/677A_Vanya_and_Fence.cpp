/***

            Bismillahir Rahmanir Rahim
            Read in the name of Allah, who created you!!!
            Author : Mehedi Hasan Shuvo,
            Department of CSE, Dhaka University of Engineering & Technology,DUET.

***/
#include<bits/stdc++.h>
using namespace std;

#define ebar_khela_jombe_besh    int main (void)
#define jitsen_bhai              return 0
#define u                        unsigned int


ebar_khela_jombe_besh
{
    u  n,h,i,ans=0;
    cin>>n>>h;
    u  a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<=h) ans++;
        else ans+=2;
    }
    cout<<ans<<endl;
    
    jitsen_bhai;
}