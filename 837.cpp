// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

using namespace __gnu_pbds;

string removeDuplicates(string s)
{
    int n = s.length();

    string ans = "";

    stack<char> q;

    for (int i = 0; i < n; i++)
    {
        if (!q.empty())
        {
            if (s[i] == q.top())
            {
                q.pop();
            }
            else
            {
                q.push(s[i]);
            }
        }
        else
        {
            q.push(s[i]);
        }
    }

    int tem = q.size();

    for (int i = 0; i < tem; i++)
    {
        ans += (q.top());

        q.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥