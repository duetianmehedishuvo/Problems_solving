#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,data,j,swap,k=0;
    vector<int> vec;
    cin>>n;
    if(n>=1 && n<=100)
    {
        for(i=0; i<n; i++)
        {
            cin>>data;
            vec.push_back(data);
        }
        for(i=0; i<n-1; i++)
        {
            swap=0;
            for(j=0; j<n-1-i; j++)
            {
                if(vec[j]>vec[j+1])
                {
                    int temp=vec[j];
                    vec[j]=vec[j+1];
                    vec[j+1]=temp;
                    swap=1;
                    k++;
                }
            }
            if(swap==0) break;
        }
        for(i=0; i<n; i++)
        {
            if(i != n-1)
            {
                printf("%d ",vec[i]);
            }
            else
            {
                printf("%d\n",vec[i]);
            }
        }
        printf("%d\n",k);
        vec.clear();
    }

    return 0;
}
