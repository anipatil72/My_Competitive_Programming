// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <chrono>

#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

// https://leetcode.com/problems/random-pick-with-blacklist/

mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

ll myRandomNumber(ll B)
{
    return (ull)rng() % (B);
}

class Solution
{

    unordered_map<int, int> m;

    int nos;

public:
    Solution(int n, vector<int> &blacklist)
    {
        int len = blacklist.size();

        sort(blacklist.begin(), blacklist.end());

        nos = n;

        vector<int> pos;

        if (len == 0)
        {
            if (n == 1)
            {
                pos = {0};
            }
            else if (n == 2)
            {
                pos = {0, 1};
            }
            else if (n == 3)
            {
                pos = {0, 1, 2};
            }
        }
        else
        {
            if (blacklist[0] > 0)
            {
                pos.push_back(0);
            }
            if (blacklist[0] > 1)
            {
                pos.push_back(1);
            }
            if (blacklist[0] > 2)
            {
                pos.push_back(2);
            }

            for (int i = 0; i < (len - 1) && (pos.size() < 7); i++)
            {
                if ((blacklist[i + 1] - blacklist[i]) == 2)
                {
                    pos.push_back(blacklist[i] + 1);
                }
                else if ((blacklist[i + 1] - blacklist[i]) == 3)
                {
                    pos.push_back(blacklist[i] + 1);
                    pos.push_back(blacklist[i] + 2);
                }
                else if ((blacklist[i + 1] - blacklist[i]) > 3)
                {
                    pos.push_back(blacklist[i] + 1);
                    pos.push_back(blacklist[i] + 2);
                    pos.push_back(blacklist[i] + 3);
                }
            }

            if (blacklist[len - 1] < n - 1)
            {
                pos.push_back(n - 1);
            }

            if (blacklist[len - 1] < n - 2)
            {
                pos.push_back(n - 2);
            }

            if (blacklist[len - 1] < n - 3)
            {
                pos.push_back(n - 3);
            }
        }

        int fine = pos.size();

        for (int i = 0; i < fine; i++)
        {
            cout << pos[i] << " ";
        }

        cout << endl;

        int tem = 0;

        for (int i = 0; i < len; i++)
        {
            m[blacklist[i]] = pos[tem++];

            if (tem == fine)
            {
                tem = 0;
            }
        }
    }

    int pick()
    {
        int mon = myRandomNumber(nos);

        if (m.count(mon) == 0)
        {
            return mon;
        }

        return m[mon];
    }
};

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥