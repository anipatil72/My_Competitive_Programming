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

bool myComp(vector<int> &a, vector<int> &b)
{
    if (a[1] == b[1])
    {
        return a[0] < b[0];
    }

    return a[1] < b[1];
}

// int maxEvents(vector<vector<int>> &events)
// {
//     int n = events.size();

//     sort(events.begin(), events.end(), myComp);

//     int ans = 0, last = events[0][0];

//     for (int i = 0; i < n; i++)
//     {
//         if (events[i][0] <= last && events[i][1] >= last)
//         {
//             ans++;

//             last++;
//         }
//     }

//     return ans;
// }

// [[1,5],[1,5],[1,5],[2,3],[2,3]]

int maxEvents(vector<vector<int>> &A)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(A.begin(), A.end());
    int i = 0, res = 0, d = 0, n = A.size();
    while (pq.size() > 0 || i < n)
    {
        if (pq.size() == 0)
        {
            d = A[i][0];
        }

        while (i < n && A[i][0] <= d)
        {
            pq.push(A[i++][1]);
        }

        pq.pop();
        ++res, ++d;

        while (pq.size() > 0 && pq.top() < d)
        {
            pq.pop();
        }
    }
    return res;
}

int main()
{

    vector<vector<int>> test = {{1, 5},
                                {1, 5},
                                {1, 5},
                                {2, 3},
                                {2, 3}};

    sort(test.begin(), test.end(), myComp);

    for (auto x : test)
    {
        cout << x[0] << " " << x[1] << endl;
    }

    cout << "This is ans : " << endl;

    cout << maxEvents(test) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥