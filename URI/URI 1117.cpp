#include <bits/stdc++.h>

using namespace std;

int main()
{

    double x,sum=0,l=0;
    while(1){

        if(l==2){
            break;
        }

        cin>>x;

        if(x<0 || x>10)
            cout<<"nota invalida"<<endl;
        else{
            l++;
            sum+=x;
        }
    }
    cout<<"media = "<<fixed<<setprecision(2)<<(sum/2.00)<<endl;

    return 0;
}
