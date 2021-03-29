#include<iostream>
#include<string>

using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string text;
        cin>>text;
        if(text.size()>10)
        {
            cout<<text[0]<<text.size()-2<<text[text.size()-1]<<endl;
        }
        else
            cout<<text<<endl;
    }
    return 0;

}
