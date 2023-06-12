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

class SummaryRanges
{
    set<int> s;

public:
    SummaryRanges()
    {
    }

    void addNum(int value)
    {
        s.insert(value);
    }

    vector<vector<int>> getIntervals()
    {
        auto it = s.begin();

        vector<vector<int>> ans;

        while (it != s.end())
        {
            int fir = *it;

            int last = fir + 1;

            it++;

            while ((it != s.end()) && (*it == last))
            {
                last++;

                it++;
            }

            ans.push_back({fir, last - 1});
        }

        return ans;
    }
};

int main()
{

    // pair<int, int> p = {2, 2};

    // // pair<int, int> q = {2, 2};

    // vector<pair<int, int>> v = {{1, 1}, {4, 7}};

    set<int> s = {1, 2, 3, 5};

    auto it = s.begin();

    while (it != s.end())
    {
        cout << *it << " ";

        it++;
    }

    // int pos = (int)(lower_bound(v.begin(), v.end(), p) - v.begin());

    // if (pos == v.size())
    // {
    //     cout << "Ended" << endl;
    // }
    // else
    // {
    //     cout << v[pos].first << "  " << v[pos].second << endl;
    // }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥