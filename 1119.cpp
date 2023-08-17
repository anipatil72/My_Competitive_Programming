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

bool isPalindrome(int *arr, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] != arr[n - 1 - i])
        {

            return false;
        }
    }

    return true;
}

vector<int> DesignIt(int *arr, int n)
{

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {

        ans[i] = arr[i];
    }

    return ans;
}

vector<int> generateNextPalindrome(int num[], int n)
{

    if (isPalindrome(num, n))
    {
        if (n & 1)
        {
            vector<int> ans = DesignIt(num, n);

            ans[n / 2] = 1;
        }
    }

    return {};
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥