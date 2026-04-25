// Sort an array using Insertion Sort
#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int n, int a[])
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = a[i];
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int a[13] = {2, 34, 67, 8, 909, 12, 34, 5, 6, 0, -1, 2, 3};
    insertion_sort(13, a);
    for (int i = 0; i < 13; i++)
    {
        cout << a[i] << " ";
    }
}