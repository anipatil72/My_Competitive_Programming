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

string solve(int c, int b, int a)
{
    // int a, b, c;

    // cin >> c >> b >> a;

    string ans = "";

    if (a == 0 && b == 0 && c > 0)
    {
        for (int i = 0; i < c + 1; i++)
        {
            ans += '0';
        }
    }
    else if (b % 2 == 0 && c > 0)
    {
        ans += '0';

        for (int i = 0; i < a + 1; i++)
        {
            ans += '1';
        }

        for (int i = 0; i < b - 1; i++)
        {
            if (i & 1)
            {
                ans += '1';
            }
            else
            {
                ans += '0';
            }
        }

        for (int i = 0; i < c; i++)
        {
            ans += '0';
        }
    }
    else
    {
        for (int i = 0; i < a + 1; i++)
        {
            ans += '1';
        }

        for (int i = 0; i < b; i++)
        {
            if (i & 1)
            {
                ans += '1';
            }
            else
            {
                ans += '0';
            }
        }

        for (int i = 0; i < c + (b != 0 && c != 0 && b % 2 == 0); i++)
        {
            ans += '0';
        }
    }

    // cout << ans << endl;

    return ans;
}

bool check(int a, int b, int c, string s)
{
    // a = number of 00 , b = number of 01 or 10 , c = number of 11

    int n = s.length();

    int x = 0, y = 0, z = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int sum = 0;

        sum += (s[i] - '0');

        sum += (s[i + 1] - '0');

        if (sum == 0)
        {
            x++;
        }
        else if (sum == 1)
        {
            y++;
        }
        else
        {
            z++;
        }
    }

    return (a == x && b == y && z == c);
}

void testing()
{
    int n = 100;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                if (i + j + k > 0 && j > 0)
                {

                    string ans = solve(i, j, k);

                    if (check(i, j, k, ans))
                    {
                    }
                    else
                    {
                        cout << "Found it!" << endl;

                        cout << i << " " << j << " " << k << endl;

                        return;
                    }
                }
            }
        }
    }

    cout << "Well Done! Accepted!" << endl;
}

int main()
{

    testing();

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥