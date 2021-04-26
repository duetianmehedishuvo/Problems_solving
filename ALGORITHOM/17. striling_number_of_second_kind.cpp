#include<bits/stdc++.h>
using namespace std;

// A C++ program to count number of partitions
// of a set with n elements into k subsets
// Returns count of different partitions of n
// elements in k subsets

int count(int n,int k){
    //base case
    if(n==0 || k==0 ||k>n) return  0;
    if(k==1||n==k) return 1;

    return count(n-1,k-1)+k*count(n-1,k);
}


int main(){

    cout<<count(3,2);

    return 0;
}

/*Table of values
Below is a triangular array of values for the Stirling numbers of the second kind (sequence A008277 in OEIS):
n\k 	0 	1 	2  	3 	   4 	   5  	6 	   7  	8  	9 	   10
0  	1
1  	0 	1
2 	   0 	1 	1
3 	   0 	1 	3 	1
4 	   0 	1 	7 	6 	   1
5 	   0 	1 	15 	25 	10 	1
6 	   0 	1 	31 	90 	65 	15 	1
7 	   0 	1 	63 	301 	350 	140 	21 	1
8 	   0 	1 	127 	966 	1701 	1050 	266 	28 	1
9 	   0 	1 	255 	3025 	7770 	6951 	2646 	462 	36 	1
10    0 	1 	511 	9330 	34105 42525 22827 5880 	750 	45 	1

As with the binomial coefficients, this table could be extended to k > n, but those entries would all be 0.
*/