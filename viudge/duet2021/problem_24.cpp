#include<bits/stdc++.h>
using namespace std;

int main()
{

    // declear Map
    map<int,int> numberSMap;
    map<int,int>::iterator iteratorNSMap;
    int n,b,ans=0;

    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&b);
        numberSMap[b]++;
    }

    for(iteratorNSMap=numberSMap.begin(); iteratorNSMap!=numberSMap.end(); ++iteratorNSMap)
    {
        if((iteratorNSMap->first)!=(iteratorNSMap->second))
        {
            if((iteratorNSMap->first)<(iteratorNSMap->second))
            {
                ans+=(iteratorNSMap->second-iteratorNSMap->first);
            }
            else ans+=iteratorNSMap->second;
        }
    }
    cout<<ans;

    return 0;
}
