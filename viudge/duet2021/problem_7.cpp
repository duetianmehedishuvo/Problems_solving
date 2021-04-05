#include<bits/stdc++.h>
using namespace std;
int func(int i,int j)
{
    int x,count=1,max=0;
    if(i>j)
    {
        int temp=i;
        i=j;
        j=temp;
    }

    while(i<=j)
    {
        x=i;
        while(x!=1)
        {
            if(x%2==0) x=x/2;
            else x=(3*x)+1;
            count++;
            if(x==1) break;
        }
        if(count>max) max=count;
        count=1;
        i++;
    }
    return max;

}
int main()
{

    int i,j,result;
    while(scanf("%d%d",&i,&j)!=EOF)
    {
        result=func(i,j);
        cout<<i<<" "<<j<<" "<<result<<endl;
    }
    return 0;
}




