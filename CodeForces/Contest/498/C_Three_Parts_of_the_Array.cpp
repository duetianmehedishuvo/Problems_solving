/*
Name: Mehedi Hasan Shuvo
Problem No: 498 C
Problem Title: Three Parts of the Array
Status: Accepted 
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int i = 0, j = n - 1;
    long long sum1 = 0, sum3 = 0, ans = 0;
    while (i <= j)
    {
        if (sum1 <= sum3)
            sum1 = sum1 + a[i++];
        else
            sum3 = sum3 + a[j--];

        if (sum1 == sum3)
            ans = max(ans, sum1);
    }
    cout << ans << "\n";

    return 0;
}