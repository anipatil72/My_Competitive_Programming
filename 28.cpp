#include <iostream>
#include <algorithm>


// C++ program to solve chocolate distribution
// problem

using namespace std;

// arr[0..n-1] represents sizes of packets
// m is number of students.
// Returns minimum difference between maximum
// and minimum values of distribution.
int findMinDiff(int arr[], int n, int m)
{
	// if there are no chocolates or number
	// of students is 0
	if (m == 0 || n == 0)
		return 0;

	// Sort the given packets
	sort(arr, arr + n);

	// Number of students cannot be more than
	// number of packets
	if (n < m)
		return -1;

	// Largest number of chocolates
	int min_diff = INT_MAX;

	// Find the subarray of size m such that
	// difference between last (maximum in case
	// of sorted) and first (minimum in case of
	// sorted) elements of subarray is minimum.

	for (int i = 0; i + m - 1 < n; i++) {
		int diff = arr[i + m - 1] - arr[i];
		if (diff < min_diff)
			min_diff = diff;
	}
	return min_diff;
}

int main()
{
	int n ;
    cin>>n ;

    scanf("\n");

    int m ;
    cin>>m ;

    scanf("\n");


    int a[n]; 

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }


	cout << "Minimum difference is "<< findMinDiff(a, n, m);
	return 0;
}


















































































































  