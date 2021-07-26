#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long int n;
    cin >> n;
    int count = 0, temp = 0;

    while (n != 0)
    {
        temp = n % 10;
        if (temp == 4 || temp == 7)
        {
            count++;
        }
        n = n / 10;
    }
    if (count == 4 || count == 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}