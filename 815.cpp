// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

void printvector(vector<int> &a)
{

    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    int n = spells.size();

    int m = potions.size();

    sort(potions.begin(), potions.end());

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        long long req = (success % spells[i] == 0 ? success / spells[i] : success / spells[i] + 1);

        // cout << req << endl;

        auto it = lower_bound(potions.begin(), potions.end(), req);

        int num = potions.end() - it;

        ans[i] = num;
    }

    return ans;
}

int main()
{

    vector<int> spells = {3, 1, 2};
    vector<int> potions = {8, 5, 8};

    ll success = 16;

    vector<int> ans = successfulPairs(spells, potions, success);

    printvector(ans);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥