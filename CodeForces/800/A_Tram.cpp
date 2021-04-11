#include<iostream>
using namespace std;
int main(){

    int n,i,a,b,max_number=0,sum=0;
    cin>>n;
    for(i=1;i<=n;i++){
        scanf("%d%d",&a,&b);

        if(i==1){
            sum=b;
        }else if(i==n){
            sum-=a;
        }else{
            sum=(sum-a)+b;
        }
        if(max_number<sum) max_number=sum;
    }
    
    cout<<max_number<<endl;
    return 0;

}