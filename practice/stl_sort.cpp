#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
} point[100];

// cmp method 01
bool cmp(Point A, Point B)
{
    if (A.x < B.x)
        return 1;
    if (A.x > B.x)
        return 0;

    if (A.y < B.y)
        return 1;
    if (A.y > B.y)
        return 0;

    return 0;
}

// cmp method 02
bool cmp2(Point A, Point B)
{
    if (A.x != B.x)
        return A.x < B.x;
    return A.y < B.y;
}

// cmp method 02 using operator overload
bool operator<(Point A, Point B)
{

    if (A.x != B.x)
        return A.x < B.x;
    return A.y < B.y;
}

int main()
{
    // int array
    int a[] = {3, 121, 34, 1, 3, 6, 3, 67, 454};
    int size = sizeof(a) / sizeof(a[0]);

    cout << "\nBefore Int  Sort: ";
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    sort(a, a + size);
    cout << "\nAfter Int array  desending Short: ";
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    sort(a, a + size, greater<int>());
    cout << "\nAfter Int array  Accessending Short: ";
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";

    // vector array
    vector<int> intVectorList = {121, 322, 441, 12, 1, 2, 4, 45};
    size = intVectorList.size();
    cout << "\n\nBefore Vector Sort: ";
    for (int i = 0; i < size; i++)
        cout << intVectorList[i] << " ";
    sort(intVectorList.begin(), intVectorList.end());
    cout << "\nAfter Vector Sort: ";
    for (int i = 0; i < size; i++)
        cout << intVectorList[i] << " ";

    // Structure array
    point[0].x = 112;
    point[0].y = 1;
    point[1].x = 23;
    point[1].y = 553;
    point[2].x = 232;
    point[2].y = 76;
    point[3].x = 5665;
    point[3].y = 32;
    point[4].x = 54;
    point[4].y = 32;
    point[5].x = 35;
    point[5].y = 86;

    cout << "\n\nBefore Structure Sort: ";
    for (int i = 0; i < 6; i++)
        cout << point[i].x << " ";
    sort(point, point + 6);
    cout << "\nAfter Structure Sort: ";
    for (int i = 0; i < 6; i++)
        cout << point[i].x << " ";

    // string sort
    vector<string> v = {"man", "oman", "Mehedi", "Hasan", "Shuvo", "Example", "Test", "test"};
    size = v.size();
    cout << "\n\nBefore Vector String Sort: ";
    for (int i = 0; i < size; i++)
        cout << v[i] << " ";
    sort(v.begin(), v.end());
    cout << "\nAfter Vector String Sort: ";
    for (int i = 0; i < size; i++)
        cout << v[i] << " ";

    return 0;
}