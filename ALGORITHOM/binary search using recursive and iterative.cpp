#include<bits/stdc++.h>
using namespace std;

int binarySearchItterative(int arr[],int left,int right,int checkNumber)
{
    while(left<=right)
    {
        int mid=left+(right-1)/2;
        if(arr[mid]==checkNumber) return mid;
        if(arr[mid]<checkNumber) left=mid+1;
        else right=mid-1;
    }
    return -1;
}

int binarySearchRecursive(int arr[],int left,int right,int checkNumber)
{

    if(right>=left)
    {
        int mid=left+(right-1)/2;
        if(arr[mid]==checkNumber) return mid;
        if(arr[mid]>checkNumber)
            return binarySearchRecursive(arr,left,mid-1,checkNumber);
        else
            return binarySearchRecursive(arr,mid+1,right,checkNumber);
    }
    // when don't fount value then return -1 value
    return -1;

}

int main()
{

    int arr[]= {2,3,4,10,34};
    int query=10;
    int arrayLength=sizeof(arr)/sizeof(arr[0]);

    // check iteraretor
    //int status=binarySearchItterative(arr,0,arrayLength-1,query);


    // check recursive
    int status=binarySearchRecursive(arr,0,arrayLength-1,query);
    if(status==-1) cout<<"Element is Not Present in Array"<<endl;
    else cout<<"Element is Present at Index: "<<status<<endl;
    return 0;
}
