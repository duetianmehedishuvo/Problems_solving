#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int>& arr)
{
    int max=*max_element(arr.begin(),arr.end());
    int min=*min_element(arr.begin(),arr.end());
    int range=max-min+1;

    vector<int> count(range);
    vector<int> output(arr.size());
    int i;
    for(i=0; i<arr.size(); i++)
    {
        count[arr[i]-min]++;
    }
    for(i=1; i<range; i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(i=arr.size()-1; i>=0; i--)
    {
        output[--count[arr[i]-min]]=arr[i];
    }
    for(i=0; i<arr.size(); i++)
    {
        arr[i]=output[i];
    }

}

void printArray(vector<int>& arr)
{

    for(int i=0; i<arr.size(); i++)
    {
        if(i != arr.size()-1)
        {
            printf("%d ",arr[i]);
        }
        else
        {
            printf("%d\n",arr[i]);
        }
    }

}

int main()
{

    int n,data;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        cin>>data;
        arr.push_back(data);
    }
    countSort(arr);
    printArray(arr);
    return 0;
}
