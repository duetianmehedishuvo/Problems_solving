#include<bits/stdc++.h>
using namespace std;

//(O(Log n) Time) 
void multiply(int F[2][2],int M[2][2]){

    int a=F[0][0]*M[0][0]+F[0][1]*M[1][0];
    int b=F[0][0]*M[0][1]+F[0][1]*M[1][1];
    int c=F[1][0]*M[0][0]+F[1][1]*M[1][0];
    int d=F[1][0]*M[0][1]+F[1][1]*M[1][1];

    F[0][0]=a;
    F[0][1]=b;
    F[1][0]=c;
    F[1][1]=d;

}

void power(int F[2][2],int n){
    if(n==0 || n==1) return;

    int M[2][2]={{1,1},{1,0}};
    power(F,n/2);
    multiply(F,F);
    if(n%2 !=0) multiply(F,M);
}

int fibonacci_matrix(int n){
    int F[2][2]={{1,1},{1,0}};
    if(n==0) return 0;
    power(F,n-1);
    return F[0][0];
}

int main(){
    int n;
    while (1)
    {
        cin>>n;
        if(n==0) break;
        cout<<fibonacci_matrix(n)<<endl;
    }
    return 0;
}

/*
                        Algorithm
Begin
   Take two 2 dimensional array
   Create a function and Perform matrix multiplication
   Create another function to find out power of matrix
   Create a function then to find out the Fibonacci number
   Multiply(arr1[2][2], arr2[2][2])
   Take 4 variables a, b, c, d
   a = arr1[0][0] * arr2[0][0] + arr1[0][1] * arr2[1][0]
   b= arr1[0][0] * arr2[0][1] + arr1[0][1] * arr2[1][1]
   c = arr1[1][0] * arr2[0][0] + arr1[1][1] * arr2[1][0]
   d = arr1[1][0] * arr2[0][1] + arr1[1][1] * arr2[1][1]
   arr1[0][0] = a
   arr1[0][1] = b
   arr1[1][0] = c
   arr1[1][1] = d
   Power(arr1[2][2], take integer n as input)
   if (n == 0 or n == 1)
      return;
   arr1 [2][2] = {{1,1}, {1,0}}
   power(arr1, n / 2)
   multiply(arr1, arr1)
   if (n mod 2 not equal to 0)
      multiply(arr1, arr2)
   fibonacci_matrix(n)
   arr1[2][2] = {{1,1}, {1,0}}
   if n ==0
      return 0
      power(arr1 n - 1)
   return arr1[0][0]
End   


*/