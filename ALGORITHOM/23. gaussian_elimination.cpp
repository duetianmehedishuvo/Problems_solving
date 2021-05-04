#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, k, n;
    float am[20][20], mul, x[10], sum;
    cout << "How many equation: ";
    cin >> n;

    // insert Data in Matrix
    for (i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << " equation coefficient ";
        for (j = 0; j < n + 1; j++)
        {
            cin >> am[i][j];
        }
    }

    // triangularization
    // convert matrix into upper tringular matrix
    
    for (k = 0; k < n - 1; k++)
    {
        for (i = k + 1; i < n; i++)
        {
            mul = am[i][k] / am[k][k];
            for (j = 0; j < n + 1; j++)
            {
                am[i][j] = am[i][j] - (am[k][j] * mul);
            }
        }
    }

    // Solve The Varisable using substitution
    x[n - 1] = am[n - 1][n] / am[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        sum = 0;
        for (j = i + 1; j < n; j++)
        {
            sum = sum + am[i][j] * x[j];
        }
        x[i] = (am[i][n] - sum) / am[i][i];
    }

    // Display
    for (i = 0; i < n; i++)
    {
        cout << "\n X[" << i + 1 << "] = " << x[i];
    }

    cout << endl;

    return 0;
}