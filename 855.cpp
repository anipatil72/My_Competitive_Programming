// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

bool wifiRange(int N, string s, int X)
{
    int n = s.length();

    vector<int> pos;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            pos.push_back(i);
        }
    }

    if (pos.size() == 0)
    {
        return 0;
    }

    int len = pos.size();

    if (pos[0] > X || (n - 1 - pos[len - 1]) > X)
    {
        return 0;
    }

    for (int i = 1; i < len; i++)
    {
        if (pos[i] - pos[i - 1] - 1 > 2 * X)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{

    cout << "Maja aa gya!" << '\n';

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥