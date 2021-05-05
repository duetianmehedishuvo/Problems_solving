#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, max;
    cin >> n;
    for (i = 1; i <= (n>=10?10:n); i++)
        {
            if(n%i==0) max=i;
        }
    cout<<max<<endl;
    return 0;
}