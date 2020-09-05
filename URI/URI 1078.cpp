#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n,i;
    cin>>n;
    if( n>1 && n<1000){
        for(i=1;i<=10;i++){
            cout<<i<<" x "<<n<<" = "<<(i*n)<<endl;
        }
    }

    return 0;
}
