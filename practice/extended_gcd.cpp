#include<bits/stdc++.h>
using namespace std;

// Function for extended Euclidean Algorithm
int gcdExtended(int a,int b,int *x,int *y){
	// base case
	if(a==0){
		*x=0;
		*y=1;
		return b;
	}
	int x1,y1; // To Store Results of recursive call
	int gcd=gcdExtended(b%a,a,&x1,&y1);

	// update x and y using result of recursive call
	*x = y1 - (b/a) * x1;
	*y = x1;
	return gcd;
}

int main(){
	int x,y,a=10,b=6;
	int g=gcdExtended(a,b,&x,&y);
	cout<<"GCD of ("<<a<<","<<b<<") = "<<g<<" x is: "<<x<<" y is: "<<y<<endl;
	return 0;
}