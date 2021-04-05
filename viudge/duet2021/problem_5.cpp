#include<iostream>
using namespace std;
int main()
{

    int n;
    int number1;
    int number2;
    cin>>n;
    char status;
    for(int i=0; i<n; i++)
    {
        cin>>number1>>number2;
        status=(number1>number2)?'>':(number1<number2)?'<':'=';
        cout<<status<<endl;
    }

    return 0;
}
