// Remove Duplicates (Sorted Array)
#include <bits/stdc++.h>
using namespace std;

int remDup(int n, int a[])
{
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[j])
        { // unique
            j++;
            a[j] = a[i];
        }
    }
    return j;
}

int main()
{
    int a[9] = {1, 1, 1, 2, 2, 3, 4, 5, 6};
    int j = remDup(9, a);
    for (int i = 0; i <= j; i++)
    {
        cout << a[i] << " ";
    }
}