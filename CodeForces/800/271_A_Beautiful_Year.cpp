/*
Name: Mehedi Hasan Shuvo
Problem No: 271A
Problem Title: Beautiful Year
Status: Accepted 
*/

#include <iostream>
using namespace std;

template <class T, int radix = 10>
bool has_duplicate_digits(T n)
{
    int digits_mask = 0;
    while (digits_mask |= (1 << (n % radix)), n /= radix)
        if (digits_mask & (1 << (n % radix)))
            return true;
    return false;
}

int main()
{

    int year, i;
    cin >> year;
    while (true)
    {
        i = year + 1;
        if (has_duplicate_digits(i) == false)
        {
            cout << i << endl;
            break;
        }
        year++;
    }

    return 0;
}