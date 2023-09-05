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

bool isNumber(string s)
{
    int n = s.length();

    int ees = 0, dots = 0, signs = 0;

    if ((s.back() > '9' || s.back() < '0') && s.back() != '.')
    {
        return false;
    }

    if (n >= 2 && (s[0] == '.' || s[0] == '+' || s[0] == '-') && (s[1] == 'e' || s[1] == 'E'))
    {

        return false;
    }

    if (n >= 3 && (s[0] == '.' || s[0] == '+' || s[0] == '-') && (s[1] == '.' || s[1] == 'E') && (s[2] == '.' || s[2] == 'e' || s[2] == 'E'))
    {

        return false;
    }

    // if ((s[0] == '+' || s[0] == '-' || s[0] == '-') && (s[1] == 'e' || s[1] == 'E'))
    // {

    //     return false;
    // }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'e' || s[i] == 'E')
        {
            ees++;

            if (i + 1 < n && s[i] == '.')
            {
                return false;
            }

            if (i >= 1 && (s[i - 1] == '+' && s[i - 1] == '-'))
            {

                return false;
            }

            if (i == 0)
            {
                return 0;
            }
        }
        else if (s[i] == '.')
        {
            dots++;

            if (i >= 1 && (s[i - 1] < '0' && s[i - 1] > '9'))
            {

                return false;
            }

            if (i + 1 < n && s[i + 1])
            {
            }
        }
        else if (s[i] == '-' || s[i] == '+')
        {
            signs++;

            if (i + 1 < n && ((s[i + 1] < '0' && s[i + 1] > '9')) && s[i + 1] != '.')
            {
                return false;
            }

            if (i >= 1 && (s[i - 1] < '0' && s[i - 1] > '9') && s[i - 1] != 'E' && s[i - 1] != 'e')
            {

                return false;
            }
        }
        else if (s[i] > '9' || s[i] < '0')
        {
            return false;
        }
    }

    if (n == 1 && (ees == 1 || dots == 1 || signs == 1))
    {
        return false;
    }

    if (dots + signs + ees == n)
    {
        return false;
    }

    if (ees >= 2 || signs > 2 || dots > 1)
    {
        return false;
    }

    bool isStart = 1, isEE = 0;

    // if (s[0]=='e'||s[i]=='E')
    // {

    // }

    for (int i = 0; i < n; i++)
    {

        // if (s[i] < '0' && s[i] > '9' && (s[i] != 'E') && (s[i] != 'e') && (s[i] != '+') && (s[i] != '-') && (s[i] != '.'))
        // {
        //     return false;
        // }

        if (isStart)
        {

            if (!isEE && dots > 0 && s[i] == '.')
            {
                dots--;
            }
            else if (signs > 0 && (s[i] == '-' || s[i] == '+'))
            {
                signs--;

                // isStart = 0;
            }
            else if (s[i] > '9' || s[i] < '0')
            {
                return false;
            }

            isStart = 0;
        }
        else if (s[i] == 'e' || s[i] == 'E')
        {
            isStart = 1;

            ees--;

            isEE = 1;
        }
        else if ((s[i] >= '0' && s[i] <= '9') || (!isEE && s[i] == '.'))
        {
            isStart = 0;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{

    int t = 100;

    while (t--)
    {
        string s;

        cin >> s;

        cout << isNumber(s) << endl;
        /* code */
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥