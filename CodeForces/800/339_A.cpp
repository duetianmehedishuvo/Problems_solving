#include<bits/stdc++.h>
using namespace std;
int main()
{

    string data,copyData;
    int a[100],n=0;
    cin>>data;
    for(int i=0; i<data.size(); i++)
    {
        if(data[i]=='+') continue;
        a[n]=(int)data[i]-48;
        n++;
    }


    for (int i = 0; i < n; i++)                     //Loop for descending ordering
    {
        for (int j = 0; j < n; j++)             //Loop for comparing other values
        {
            if (a[j] > a[i])                //Comparing other array elements
            {
                int tmp = a[i];         //Using temporary variable for storing last value
                a[i] = a[j];            //replacing value
                a[j] = tmp;             //storing last value
            }
        }
    }

    for (int i = 0; i < n; i++)                     //Loop for printing array data after sorting
    {
        cout<<(i==0?"":"+")<<a[i];                  //Printing data
    }
    cout<<endl;

    return 0;
}

