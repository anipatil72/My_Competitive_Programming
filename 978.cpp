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

// https://leetcode.com/problems/number-of-squareful-arrays/ Must Solve, Very good Concept

bool isPerfectSquare(int a)
{
    double test = 1.0 * a;

    double dos = sqrt(test);

    double integ = floor(dos);

    return integ == dos;
}

void recur(int index, vector<int> &sorted, int vis, int &ans, int parent)
{
    int n = sorted.size();

    if (index == n)
    {
        ans++;
        return;
    }

    int des = 0, def = -1;

    while (des < n)
    {
        if (sorted[des] == def)
        {
        }
        else if (((1 << des) & (vis)) > 0)
        {
            if (index == 0 || (isPerfectSquare(parent + sorted[des])))
            {
                vis ^= (1 << des);

                def = sorted[des];

                recur(index + 1, sorted, vis, ans, sorted[des]);

                vis ^= (1 << des);
            }
        }

        des++;
    }
}

int numSquarefulPerms(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
    {
        return 1;
    }

    sort(nums.begin(), nums.end());

    int ans = 0;

    int visited = (1 << (n + 1)) - 1;

    recur(0, nums, visited, ans, 0);

    return ans;
}

int main()
{
    // cout << isPerfectSquare(3) << endl;
    // cout << isPerfectSquare(1) << endl;

    vector<int> a = {2, 2, 2};

    cout << numSquarefulPerms(a);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥