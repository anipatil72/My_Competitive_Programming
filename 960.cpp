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

const int N = 1000001;
vector<int> spf(N + 1);
void precompute()
{
    for (int i = 2; i <= N; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i * i <= N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= N; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    return;
}
void solve()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    precompute();
    // print(spf) ;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        int x = v[i];
        // actual log(n) calculation
        set<int> st;
        while (x > 1)
        {
            int temp = spf[x];
            if (st.find(temp) == st.end())
            {
                st.insert(temp);
                mp[temp].push_back(v[i]);
            }
            x = x / temp;
        }
    }
    int ans = 1;
    for (auto it : mp)
    {
        vector<int> v = it.second;
        int k = v.size();
        ans = max(ans, k);
    }

    cout << ans << endl;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥