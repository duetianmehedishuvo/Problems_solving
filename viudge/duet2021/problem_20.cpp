#include <bits/stdc++.h>
using namespace std;

struct DNA
{
    string title;
    int rev;
};

bool comp(DNA a,DNA b)
{
    return (a.rev<b.rev);
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int m,n,i,j,k;
        cin>>n>>m;
        DNA dna[m];
        for(i=0; i<m; i++)
        {
            cin>>dna[i].title;
            int r=0;
            for(j=0; j<n-1; j++)
            {
                for(k=j+1; k<n; k++)
                {
                    if(dna[i].title[j]>dna[i].title[k]) r++;
                }
            }
            dna[i].rev=r;
        }
        stable_sort(dna,dna+m,comp);
        for(i=0; i<m; i++)
            cout<<dna[i].title<<endl;

        if(test>0) cout<<endl;
    }

    return 0;
}
