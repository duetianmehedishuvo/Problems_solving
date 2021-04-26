#include<bits/stdc++.h>
using namespace std;

//countDer(n) = (n - 1) * [countDer(n - 1) + countDer(n - 2)]
// Time Complexity O(n)=T(n-1)+T(n-2)

int derangementNumber(int n){
    if(n==1) return 0;
    if(n==2) return 1;

    return (n-1)*(derangementNumber(n-2)+derangementNumber(n-1));
}

int main(){

int n = 4;
    cout << "Count of Derangements is "
         << derangementNumber(n);

    return 0;
}