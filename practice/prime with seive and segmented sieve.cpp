#include<bits/stdc++.h>
using namespace std;

// Time Complexity is 0(n)
int primeItterative(int n){
    if(n<=1) return 0;
    for(int i=2;i<n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}

// Time Complexity is 0(sqrt(n))
int primeSqrt(int n){
    if(n<=1) return 0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}

// Sieve Method Time Complexity 0(nloglogn)
// I Prefere vector
int prime[300000],nPrime;
// 1 if not prime, 0 if prime
int mark[1000002];
void seive(int n){
int i,j,limit=sqrt(n*1)+2;

// 1 is not prime. you can also mark 1
mark[1]=1;

// almost all the evens are not prime
for(i=4;i<=n;i+=2) mark[i]=1;

// 2 is prime
prime[nPrime++]=2;

// run loop for only odds
for(i=3;i<=n;i+=2){
   // if not prime, no need to do multiple cutting
    if(!mark[i]){
        // i is prime
        prime[nPrime++]=i;
        
        // if we don't fo it, following
        //i*i may overflow
        if(i<=limit){
            // loop through all odd multiples of i
            // greater than i*i
            for(j=i;j<=n;j+=i*2){
                // mark j not prime
                mark[j]=1;
            }
        }
    } 
}

}

// Segmented Sieve like found 30  to 700 Prime Number
typedef long long ll;
vector<int> primes;
#define MAX 32000
void seiveForSegment(){
    bool isPrime[MAX];
    for(int i=0;i<MAX;++i) isPrime[i]=true;
    for(int i=3;i*i<=MAX;i+=2){
        if(isPrime[i]){
            for(int j=i*i;j<=MAX;j+=i) isPrime[i]=false;
        }
    }
    primes.push_back(2);
    for(int i=3;i<MAX;i+=2){
        if(isPrime[i]) primes.push_back(i);
    }

}


void segmentedSieve(ll L, ll R)
{
 bool isPrime[R-L+1];
 for(int i=0 ; i<=R-L+1 ; ++i)
    isPrime[i]=true;
    
 if(L==1)
    isPrime[0]=false;
    
 for(int i=0 ; primes[i]*primes[i]<=R ; i=++i)
 {
    ll curPrime=primes[i];
    ll base=(L/curPrime)*curPrime;
    if(base<L)
    {
       base+=curPrime;
    }
    for(ll j=base ; j<=R ; j+=curPrime){
        isPrime[j-L]=false;
    }
    if(base==curPrime) isPrime[base-L]=true;
    
 }

 for(int i=0 ; i<R-L+1 ; ++i)
 {
    if(isPrime[i]==true)
        cout<<L+i<<endl;
 }
}


int main(){

    int n=11;
    cout<<"Itterative Way: "<<endl;
    if(primeItterative(n)==0) 
        cout<<"Not Prime"<<endl;
    else 
        cout<<"Number is Prime: "<<n<<endl;


    cout<<"\nUsing sqrt Way: "<<endl;
    if(primeSqrt(n)==0) 
        cout<<"Not Prime"<<endl;
    else 
        cout<<"Number is Prime: "<<n<<endl;

// print all prime number
cout<<"\nUsing Seive Method: "<<endl;
seive(n);

int size=sqrt(n*1)+2; 
int checkStatus=1;
for(int i=0;i<size;i++){ 
    cout<<prime[i]<<" ";
    if(prime[i]==n) {
        checkStatus=0;
        break;
    }
    else checkStatus=1;
}

if(checkStatus==0)  cout<<"\nNumber is Prime: "<<n<<endl;
else cout<<"\nNot Prime"<<endl;

// Segment Seive Example
cout<<"\nSegment Seive Method: "<<endl;
seiveForSegment();
segmentedSieve(30,50);

    return 0;
}