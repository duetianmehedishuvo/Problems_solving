#include<bits/stdc++.h>
using namespace std;
int main()
{

// Method 01
cout<<"Normal Prime Number Print"<<endl;
    int i,count,j;
    for(int i=1; i<=100; i++)
    {
        count=0;
        for(j=2; j<=i/2; j++)
        {
            if(i%j==0)
            {
                count++;
                break;
            }
        }
        if(count==0 && i!=1) cout<<i<<" ";
    }

    // Method 02
    cout<<endl<<endl<<"Normal Prime Number print using sqrt function Print"<<endl;
    for(int i=1; i<=100; i++)
    {
        count=0;
        for(j=2; j<=sqrt(i); j++)
        {
            if(i%j==0)
            {
                count++;
                break;
            }
        }
        if(count==0 && i!=1) cout<<i<<" ";
    }


    //seive for print prime number
    int n=100;
    int visited[200];
    memset(visited,0,sizeof(visited));

    vector<int> vec;

    for(i=4;i<=n;i+=2) visited[i]=1;

    for(i=3;i<=sqrt(n);i+=2){
        if(visited[i]==0){
            for(int j=i*i;j<=n;j+=(i*2)) visited[j]=1;
        }
    }


    cout<<endl<<endl<<"Seive Print"<<endl;
    for(i=2;i<=n;i++){
        if(visited[i]==0) vec.push_back(i);
    }
    for(i=0;i<vec.size();++i){
        cout<<vec[i]<<" ";
    }


    return 0;
}
