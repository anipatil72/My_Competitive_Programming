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

long long maxKelements(vector<int> &nums, int k)
{
    int n = nums.size();

    ll ans = 0;

    priority_queue<int> p(nums.begin(), nums.end());
    bool flag = false;

    for (int i = 0; i < k; i++)
    {
        int tem = p.top();

        p.pop();

        ans += ceil(1.0 * tem / 3);
    }

    return 0;
}

int main()
{

    int des = ceil(4.0 / 3);

    cout << des << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥