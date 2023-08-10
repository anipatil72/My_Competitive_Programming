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

// bool myComp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
// {
//     return a.first < b.first;
// }

bool check(vector<int> &nums, int p, long long diff)
{
    int n = nums.size();

    int count = 0;

    int i = 0;

    while (i < n - 1)
    {
        if (abs(nums[i] - nums[i + 1]) <= diff)
        {
            count++;

            i += 2;
        }
        else
        {
            i++;
        }
    }

    return count >= p;
}

int minimizeMax(vector<int> &nums, int p)
{
    int n = nums.size();

    // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

    sort(nums.begin(), nums.end());

    int right = nums.back() - nums[0];

    int left = 0;

    int ans = 0;

    while (left < right)
    {
        long long mid = (left + 0LL + right) / 2;

        if (check(nums, p, mid))
        {
            right = mid;

            ans = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    // vector<pair<int, int>> v(n);

    // for (int i = 0; i < n; i++)
    // {
    //     v[i] = {nums[i], i};
    // }

    // unordered_set<int> s;

    // for (int i = 0; i < n - 1; i++)
    // {
    //     pair<int, pair<int, int>> des = {abs(v[i].first - v[i + 1].first), {v[i].second, v[i + 1].second}};

    //     q.push(des);
    // }

    // int ans = 0, count = 0;

    // for (int i = 0; count < p; i++)
    // {
    //     auto cur = q.top();

    //     int fir = cur.second.first, sec = cur.second.second;

    //     // cout << "This is at the top : " << cur.first << endl;

    //     if (s.count(fir) == 0 && s.count(sec) == 0)
    //     {

    //         s.insert(cur.second.first);
    //         s.insert(cur.second.second);

    //         ans = max(ans, cur.first);

    //         count++;
    //     }

    //     q.pop();
    // }

    return ans;
}

// [3,4,2,3,2,1,2]
// 3

int main()
{

    vector<int> nums = {10, 1, 2, 7, 1, 3};

    int p = 2;

    cout << minimizeMax(nums, p);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥