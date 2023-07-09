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

// int distributeCookies(vector<int> &cookies, int k)
// {
//     int n = cookies.size();

//     priority_queue<int, vector<int>, greater<int>> q;

//     sort(cookies.begin(), cookies.end());

//     for (int i = 0; i < k; i++)
//     {
//         q.push(cookies[i]);
//     }

//     for (int i = k; i < n; i++)
//     {
//         int des = q.top();

//         des += cookies[i];

//         q.pop();

//         q.push(des);
//     }

//     int ans = 0;

//     while (!q.empty())
//     {
//         ans = max(ans, q.top());

//         q.pop();
//     }

//     return ans;
// }

int check(vector<int> &fin)
{
}

int recur(int index, vector<int> &nums, vector<int> &fin, int &ans)
{
    int n = nums.size();

    int k = fin.size();

    if (index == n)
    {
        return ans = max(ans, check(fin));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int des = fin[i];

            des |= (1 << i);
        }
    }
}

int distributeCookies(vector<int> &cookies, int k)
{
    int n = cookies.size();
    vector<int> fin(k, 0);
}
int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥