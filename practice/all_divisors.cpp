#include<bits/stdc++.h>
using namespace std;

vector<int> divisor[1000002];
void divisiors(int n){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            divisor[j].push_back(i);
        }
    }
}


void printElements()
{
  int sum=0;
    for (int i = 1; i <= 20; i++) {  
        cout << "Elements at index "<< i << ": ";
        for (auto it = divisor[i].begin();it != divisor[i].end(); it++) {
            sum+=*it;
            cout << *it <<"+ ";
        }
        cout <<" = "<< sum;
        sum=0;
        cout << endl;
    }
}


int main(){

    divisiors(20);

    printElements();
    return 0;
}