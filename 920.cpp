// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {

        vector<pair<int, int>> v;

        for (int i = 0; i < nums1.size(); i++)
        {
            v.push_back({nums2[i], nums1[i]});
        }

        sort(v.rbegin(), v.rend());

        long long ans = 0;
        long long currSum = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < k - 1; i++)
        {
            currSum += v[i].second;
            pq.push(v[i].second);
        }

        for (int i = k - 1; i < nums1.size(); i++)
        {
            currSum += v[i].second;
            pq.push(v[i].second);
            ans = max(ans, currSum * v[i].first);

            currSum -= pq.top();
            pq.pop();
        }

        return ans;
    }
};

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

bool myComp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n = nums1.size();

    vector<pair<int, int>> pos;

    for (int i = 0; i < n; i++)
    {
        pos.push_back({nums1[i], nums2[i]});
    }

    sort(pos.begin(), pos.end(), myComp);

    vector<int> nis;

    long long sum = 0;

    for (int i = 0; i < k; i++)
    {
        // nis.push_back(pos[i].first);

        sum += pos[i].first;
    }

    long long ans = pos[k - 1].second * 1LL * sum;

    return ans;
}

int main()
{

    vector<int> a = {4, 2, 3, 1, 1};
    vector<int> b = {7, 5, 10, 9, 6};

    int k = 1;

    cout << maxScore(a, b, k);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥