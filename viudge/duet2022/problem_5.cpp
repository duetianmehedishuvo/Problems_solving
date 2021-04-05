#include<iostream>

using namespace std;
int main()
{

    int m,n,i,status=0,check=0;
    cin>>m>>n;
    check=m;
    char ch;
    if(m>=1 && m<=100 && n>=1 && n<=100)
    {
        while(m--)
        {

            for(i=0; i<n; i++)
            {
                cin>>ch;
                if(ch=='W') status++;
            }
        }

        cout<<status/check<<endl;
    }

    return 0;
}
