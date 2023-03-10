// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

int maxSum(vector<int> &nums1, vector<int> &nums2)
{

    ll n1 = nums1.size();
    ll n2 = nums2.size();

    vector<vector<int>::iterator> a;
    vector<vector<int>::iterator> b;

    a.push_back(nums1.begin());
    b.push_back(nums2.begin());

    if (n1 > n2)
    {
        for (ll i = 0; i < n2; i++)
        {
            if (binary_search(nums1.begin(), nums1.end(), nums2[i]))
            {

                auto it = lower_bound(nums1.begin(), nums1.end(), nums2[i]);

                a.push_back(it);

                b.push_back(nums2.begin() + i);
            }
        }
    }
    else
    {

        for (ll i = 0; i < n1; i++)
        {
            if (binary_search(nums2.begin(), nums2.end(), nums1[i]))
            {

                auto it = lower_bound(nums2.begin(), nums2.end(), nums1[i]);

                a.push_back(nums1.begin() + i);

                b.push_back(it);
            }
        }
    }

    a.push_back(nums1.end());
    b.push_back(nums2.end());

    ll ans = 0;

    int net = 0;

    for (ll i = 1; i < a.size(); i++)
    {

        auto x = a[i];
        auto y = a[i - 1];

        auto g = b[i];
        auto h = b[i - 1];

        ll sum1 = accumulate(y, x, 0LL);
        ll sum2 = accumulate(h, g, 0LL);

        ans += max(sum1, sum2);

        ans = ans % M;
    }

    return ans;
}

int main()
{

    vector<int> nums1 = {2, 4, 5, 8, 10};
    vector<int> nums2 = {4, 6, 8, 9};

    int an = maxSum(nums1, nums2);

    cout << an << endl;

    // cout<<accumulate(nums1.begin(), nums1.begin(), 0);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥