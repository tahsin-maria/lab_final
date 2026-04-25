// Search an element using binary Search in a sorted array
#include <bits/stdc++.h>
using namespace std;

void BS(int n, int a[], int val)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == val)
        {
            cout << "value found at index " << mid << endl;
            return;
        }
        else if (a[mid] < val)
        {
            l = mid + 1;
        }
        else if (a[mid] > val)
        {
            r = mid - 1;
        }
    }
    cout << "value not found\n";
}

int main()
{
    int a[9] = {1, 1, 1, 2, 2, 3, 4, 5, 6};
    int val;
    cout << "enter the value:";
    cin >> val;
    BS(9, a, val);
}