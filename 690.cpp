// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    ll n = temperatures.size();

    stack<pair<ll, ll>> s;

    vector<int> a(n);

    a[n - 1] = -1;

    s.push({a[n - 1], n - 1});

    for (ll i = n - 1; i >= 0; i--)
    {

        while (!s.empty() && s.top().first <= temperatures[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            a[i] = -1;
        }
        else
        {
            a[i] = s.top().second - i;
        }
    }

    return a;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥