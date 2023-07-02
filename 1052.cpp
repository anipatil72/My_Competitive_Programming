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

void solve()
{
    ordered_set gat;

    ll n, k;

    cin >> n >> k;

    unordered_map<ll, ll> m;

    for (int i = 0; i < n; i++)
    {
        long long x;

        cin >> x;

        bool flag = 0;

        if (m.count(x) == 0)
        {

            flag = !flag;

            m[x]++;

            gat.insert(x);
        }
    }

    for (int i = 0; i < k; i++)
    {
        long long p;

        int tem = 0;

        cin >> p;

        if (m.count(p) == 0)
        {
            m[p]++;

            tem++;

            gat.insert(p);
        }

        ll ans = gat.size();

        long long des = gat.order_of_key(p);

        cout << (ans - des) << endl;
    }

    // Done
}

int main()
{

    solve();

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥