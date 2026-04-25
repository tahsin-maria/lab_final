// Second Largest Element
#include <bits/stdc++.h>
using namespace std;

int secLarg(int n, int a[])
{
    int first = a[0], sec = -1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > first)
        {
            sec = first;
            first = a[i];
        }
        else if (a[i] > sec && a[i] != first)
        {
            sec = a[i];
        }
    }
    return sec;
}

int main()
{
    int a[13] = {2, 34, 67, 8, 909, 12, 34, 5, 6, 0, -1, 2, 3};
    cout << "Second largest element is = " << secLarg(13, a);
}