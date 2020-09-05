#include <iostream>
#include<string.h>

using namespace std;

int main()
{

    int n,i,number;
    cin>>n;
    if( n<10000){
        for(i=1;i<=n;i++){
            cin>>number;
            if(number>0){
                if(number%2==0){
                    cout<<"EVEN POSITIVE"<<endl;
                }else{
                    cout<<"ODD POSITIVE"<<endl;
                }
            }else if(number<0){
                if(number%2==0){
                    cout<<"EVEN NEGATIVE"<<endl;
                }else{
                    cout<<"ODD NEGATIVE"<<endl;
                }
            }else
            cout<<"NULL"<<endl;
        }
    }

    return 0;
}
