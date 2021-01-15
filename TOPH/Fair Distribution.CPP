#include <iostream>

using namespace std;

int main()
{
    int child,chocolate;
    cin>>child>>chocolate;
    if(chocolate<child) cout<<child-chocolate<<endl;
    else
    {
        if(chocolate%child==0) cout<<"0"<<endl;
        else cout<<child-(chocolate%child);
    }

    return 0;
}
