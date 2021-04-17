#include<bits/stdc++.h>
using namespace std;

/*
that solution would  be able to handle cases where n <=10^6 
We know,
log(a*b) = log(a) + log(b)

Therefore
log( n! ) = log(1*2*3....... * n) 
          = log(1) + log(2) + ........ +log(n)

Now, observe that the floor value of log base 
10 increased by 1, of any number, gives the
number of digits present in that number.

Hence, output would be : floor(log(n!)) + 1.

Time Complexity 0(n)
*/

int findDigit(int n){
    if(n==0) return 0;
    if(n<=1) return 1;

    double digit=0;
    for(int i=2;i<=n;i++){
        digit+=log10(i);
    }
    return floor(digit)+1;

}

/*
However that solution would not be able to handle cases where n >10^6 
We can use Kamenetsky’s formula to find our answer ! 
 

It approximates the number of digits in a factorial by :
f(x) =    log10( ((n/e)^n) * sqrt(2*pi*n))

Thus, we can pretty easily use the property of logarithms to,
f(x) = n* log10(( n/ e)) + log10(2*pi*n)/2

Time Complexity 0(1)

*/

long long findDigitUsingKamenetskyFormula(int n){
    if(n==0) return 0;
    if(n<=1) return 1;
    double x=0;
    x=n*log10(n/M_E)+(log10(2*M_PI*n))/2.0;
    return floor(x)+1;
}

int main(){

    // find digit using noral concept
    cout<<"Find Digit Using normal Way\n\n";
    cout<<"1: "<<findDigit(1)<<endl;
    cout<<"2: "<<findDigit(2)<<endl;
    cout<<"7: "<<findDigit(7)<<endl;
    cout<<"50: "<<findDigit(50)<<endl;
    cout<<"60: "<<findDigit(60)<<endl;
    // find digit using kamenetsky's concept
    cout<<"\n\nFind Digit Using kamenetsky's Way\n\n";
    cout << findDigitUsingKamenetskyFormula(1) << endl;
    cout << findDigitUsingKamenetskyFormula(50000000) << endl;
    cout << findDigitUsingKamenetskyFormula(1000000000) << endl;
    cout << findDigitUsingKamenetskyFormula(120) << endl;

    return 0;
}