/*
Name: Mehedi Hasan Shuvo
Problem No: 734A
Problem Title: Anton and Danik
Status: Accepted 
*/

#include <iostream>
#include<string>
using namespace std;

int main()
{
    int n, anton = 0, danik = 0;
    string gamesWinsStatus;
    cin >> n >> gamesWinsStatus;
    for (int i = 0; i < n; i++)
    {
        if (gamesWinsStatus[i] == 'A')
            anton++;
        else
            danik++;
    }
    if (anton > danik)
        cout << "Anton" << endl;
    else if (anton < danik)
        cout << "Danik" << endl;
    else
        cout << "Friendship" << endl;

    return 0;
}