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

class Solution
{
    unordered_map<int, int> m;

public:
    // Function to insert element into the queue
    void insert(queue<int> &q, int k)
    {

        m[k]++;

        q.push(k);
        // Your code here
    }

    // Function to find frequency of an element
    // return the frequency of k
    int findFrequency(queue<int> &q, int k)
    {

        if (m.count(k) == 0)
        {
            return -1;
        }

        return m[k];

        // Your code here
    }
};

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥