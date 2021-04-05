#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,data,j,temp,k=0,min_index;
    vector<int> vec;
    cin>>n;
    if(n>=1 && n<=100)
    {
        for(i=0; i<n; i++)
        {
            cin>>data;
            vec.push_back(data);
        }
        for(i=0; i<n; i++)
        {
            min_index=i;

            for(j=i+1; j<n; j++)
            {
                if(vec[j]<vec[min_index])
                {
                    min_index=j;

                }
            }
            if(vec[i]!=vec[min_index]) k++;
            int temp=vec[i];
            vec[i]=vec[min_index];
            vec[min_index]=temp;
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
