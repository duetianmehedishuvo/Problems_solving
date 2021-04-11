#include<iostream>
using namespace std;
int main(){

    int n,person;
    cin>>n;
    if(n<6) person=1;
    else if(n>=6 && n<12) person=2;
    else person=n/6+1;
    cout<<person<<endl;

return 0;
}
