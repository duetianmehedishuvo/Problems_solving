#include<iostream>
#include<string>
using namespace std;

int main()
{
    string number;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        number+=to_string(i);
    }
    cout<<number[n-1];
    return 0;
}
