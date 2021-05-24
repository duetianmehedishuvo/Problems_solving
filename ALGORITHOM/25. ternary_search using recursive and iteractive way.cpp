#include <bits/stdc++.h>
using namespace std;

int ternarySearchItterative(int arr[], int left, int right, int checkNumber)
{
    while (left <= right)
    {
        // find the mid1 and mid2
        int mid1 = (2 * left + right) / 3;
        int mid2 = (left + 2 * right) / 3;

        // check if key is present at any mid
        if (arr[mid1] == checkNumber)
            return mid1;
        if (arr[mid2] == checkNumber)
            return mid2;

        //since key is not present at mid
        //check in which region it is present
        //then repeat thr search operation in that region
        if (arr[mid1] > checkNumber)

            // thr key lies in between 1 and mid1
            right = mid1 - 1;
        else if (arr[mid2] > checkNumber)

            // the key lies in between mid and right
            left = mid2 + 1;
        else
        {
            // The key lies in between mid1 and mid2
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    // key not found
    return -1;
}

int ternarySearchRecursive(int arr[], int left, int right, int checkNumber)
{
    if (left <= right)
    {

        // find the mid1 and mid2
        int mid1 = (2 * left + right) / 3;
        int mid2 = (left + 2 * right) / 3;

        //check if key is present at any mid
        if (arr[mid1] == checkNumber)
            return mid1;
        if (arr[mid2] == checkNumber)
            return mid2;

        //since key is not present at mid
        //check in which region it is present then repeat the search operation in that program
        if (arr[mid1] > checkNumber)
            return ternarySearchRecursive(arr, left, mid1 - 1, checkNumber);
        else if (arr[mid2] > checkNumber)
            return ternarySearchRecursive(arr, mid2 + 1, right, checkNumber);
        else
            return ternarySearchRecursive(arr, mid1 + 1, mid2 - 1, checkNumber);
    }

    // key not found
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 34};
    int query = 4;
    int arrayLength = sizeof(arr) / sizeof(arr[0]);

    //Iteractive Apporace of Ternary Search

    int status1 = ternarySearchItterative(arr, 0, arrayLength - 1, query);

    //Recursive Apporace of Ternary Search

    int status = ternarySearchRecursive(arr, 0, arrayLength - 1, query);

    if (status == -1)
        cout << "Element is Not Present in Array" << endl;
    else
        cout << "Element is Present at Index: " << status << endl;
    return 0;
}