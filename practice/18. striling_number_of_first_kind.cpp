#include<bits/stdc++.h>
using namespace std;

//the  base cases: S(0, 0) = 1, S(n, 0) = 0 and S(0, n) = 0.
//s1(n, k) = -(n - 1) * s1(n - 1, k) + s1(n - 1, k - 1)

int count(int n,int k){
    //base case
    if(n==0 && k==0 ) return  1;
    else if(n==0 || k==0 ) return  0;
    
    return count(n-1,k-1)+(n-1)*count(n-1,k);
}


int main(){

    cout<<count(5,3);

    return 0;
}

/*Table of values
Below is a triangular array of unsigned values for the Stirling numbers of the first kind, similar in form to Pascal's triangle. These values are easy to generate using the recurrence relation in the previous section.

k
n
0	1	2	3	4	5	6	7	8	9
0	1
1	0	1
2	0	1	1
3	0	2	3	1
4	0	6	11	6	1
5	0	24	50	35	10	1
6	0	120	274	225	85	15	1
7	0	720	1764	1624	735	175	21	1
8	0	5040	13068	13132	6769	1960	322	28	1
9	0	40320	109584	118124	67284	22449	4536	546	36	1

*/