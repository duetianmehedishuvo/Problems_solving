#include<bits/stdc++.h>
using namespace std;
int main()
{
    int number,saveNumber=0,number2=0;
    cin>>number;
    if(number>=100 && number<=999)
    {
        saveNumber=number;
        while(number!=0)
        {

            int mod=number%10;
            number2=number2*10+mod;
            number/=10;
        }
        if(number2==saveNumber) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }


    return 0;
}
