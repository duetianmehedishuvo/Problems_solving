#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,data,j,temp,k;
    vector<int> vec;
    cin>>n;
    for(i=0; i<n; i++)
    {
        scanf("%d",&data);
        vec.push_back(data);
    }
    for(i=0; i<n; i++)
    {
        j=i;
        while(j>0 && (vec[j]<vec[j-1]))
        {
            temp=vec[j];
            vec[j]=vec[j-1];
            vec[j-1]=temp;
            j--;
        }
        for(k=0; k<n; k++) cout<< (k==0?"":" ") <<vec[k];
        cout << endl;

    }

    vec.clear();
    return 0;
}
