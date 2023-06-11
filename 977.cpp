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

// https://leetcode.com/problems/snapshot-array/

class SnapshotArray
{
    vector<vector<int>> changes, values;

    int snaps;

public:
    SnapshotArray(int length)
    {
        changes.resize(length);
        values.resize(length);

        snaps = 0;
    }

    void set(int index, int val)
    {
        if (changes[index].size() == 0)
        {
            changes[index].push_back(snaps);

            values[index].push_back(val);
        }
        else
        {
            if (changes[index].back() == snaps)
            {
                values[index][changes[index].size() - 1] = val;
            }
            else
            {

                changes[index].push_back(snaps);

                values[index].push_back(val);
            }
        }
    }

    int snap()
    {
        return snaps++;
    }

    int get(int index, int snap_id)
    {
        int it = (int)(lower_bound(changes[index].begin(), changes[index].end(), snap_id) - changes[index].begin());

        if (it == changes[index].size() && changes[index].size() == 0)
        {
            return 0;
        }

        if (it == changes[index].size())
        {
            return values[index].back();
        }

        if (it == 0)
        {
            if (changes[index][it] > snap_id)
            {
                return 0;
            }
            else
            {
                return values[index][it];
            }
        }
        else
        {

            if (changes[index][it] > snap_id)
            {
                return values[index][it - 1];
            }

            return values[index][it];
        }
    }
};

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥