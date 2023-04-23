// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

vector<long long> smallerSum(int n, vector<int> &arr)
{

    vector<pair<int, int>> org(n);

    for (int i = 0; i < n; i++)
    {
        org[i] = {arr[i], i};
    }

    sort(org.begin(), org.end());

    long long sum = 0;

    vector<long long> ans(n);

    int cur = org[0].first;

    long long tem = sum;

    for (int i = 0; i < n; i++)
    {
        if (cur == org[i].first)
        {
            ans[i] = tem;

            sum += org[i].first;
        }
        else
        {
            cur = org[i].first;

            tem = sum;

            ans[i] = tem;

            sum += org[i].first;
        }
    }

    vector<long long> fin(n);

    for (int i = 0; i < n; i++)
    {
        fin[org[i].second] = ans[i];
    }

    return fin;
}

int main()
{

    vector<int> v = {4, 4, 4};

    vector<long long> ans = smallerSum(3, v);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥