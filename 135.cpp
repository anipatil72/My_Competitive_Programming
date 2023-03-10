#include <bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int n, int k)
{

    int low = 0, high = n - 1;

    int mid = (low + high) / 2;

    while (low <= high)
    {
        if (arr[low] == k)
        {
            return low;
        }

        if (arr[high] == k)
        {
            return high;
        }

        if (arr[mid] == k)
        {
            return mid;
        }

        if (arr[mid] < k)
        {

            low = mid + 1;
            high = high - 1;
        }

        if (arr[mid] > k)
        {
            high = mid - 1;
            low++;
        }

        mid = (low + high) / 2;
    }

    return -1;
}

int main()
{

    return 0;
}