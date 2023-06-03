// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int maxIndexDiff(int arr[], int n)
{
    int tem = 0;

    vector<int> leftmin(n), rightmax(n);

    leftmin[0] = arr[0];

    rightmax[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
    {
        leftmin[i] = min(arr[i], leftmin[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        rightmax[i] = max(arr[i], rightmax[i + 1]);
    }

    int a = 0, b = 0;

    while (a < n && b < n)
    {
        if (leftmin[a] <= rightmax[b])
        {
            b++;

            tem = max(tem, b - a);
        }
        else
        {
            a++;
        }
    }

    return tem;
}

int main()
{

    cout << "Hey There! " << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥