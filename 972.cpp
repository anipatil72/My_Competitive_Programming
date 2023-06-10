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

string rremove(string s)
{

    string ans = "";

    char c;

    int k = 0, pos = 0;

    while (true)
    {
        k = 0;

        c = '1';
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            if ((i < n - 1) && (s[i] == s[i + 1]))
            {
                c = s[i], k = 1;
            }

            if (s[i] != c)
            {
                ans += s[i], c = s[i];
            }
        }

        s = ans;

        ans = "";

        if (k == 0)
        {
            break;
        }
    }

    // stack<char> st;

    // for (int i = 0; i < n; i++)
    // {
    //     if (st.empty())
    //     {
    //         st.push(s[i]);
    //     }
    //     else
    //     {
    //         if (st.top() == s[i])
    //         {
    //             while (!st.empty() && (st.top() == s[i]))
    //             {
    //                 st.pop();
    //             }
    //         }
    //         else
    //         {
    //             st.push(s[i]);
    //         }
    //     }
    // }

    // string ans = "";

    // while (!st.empty())
    // {
    //     ans += st.top();

    //     st.pop();
    // }

    // reverse(ans.begin(), ans.end());

    return s;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥