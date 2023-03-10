#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int k)
{

    int low = 0, mid, high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        // cout<<" I am here ! "<<endl;

        if (a[mid] == k)
        {
            return mid;
        }

        if (a[low] == k)
        {
            return low;
        }

        if (a[high] == k)
        {
            return high;
        }

        if (k > a[mid])
        {
            low = mid + 1;
        }

        if (k < a[mid])
        {
            high = mid - 1;
        }
    }

    return -1 ;

}

int main()
{

    int n;

    cin >> n;

    scanf("\n");

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "The element 5 is at position " << binarySearch(a, n, 5);

    return 0;
}