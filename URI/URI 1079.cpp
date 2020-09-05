#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n,i;
    double a,b,c,totalavg;
    cin>>n;

        for(i=1;i<=n;i++){
            cin>>a>>b>>c;

            totalavg=((a*2)+(b*3)+(c*5))/(10);
            cout<<fixed<<setprecision(1)<<totalavg<<endl;
        }


    return 0;
}
