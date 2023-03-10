// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

int minStoneSum(vector<int> &piles, int k)
{

    ll n = piles.size();

    priority_queue<int> p;

    for (ll i = 0; i < n; i++)
    {
        p.push(piles[i]);
    }

    for (ll i = 0; i < k; i++)
    {
        ll t = p.top();

        t -= t / 2;

        p.pop();

        p.push(t);
    }

    ll ans = 0;

    for (ll i = 0; i < p.size(); i++)
    {

        ans += p.top();

        cout<<p.top()<<endl;

        p.pop();
    }

    // int ans = accumulate(piles.begin(), piles.end(), 0);

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥