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

string largestMultipleOfThree(vector<int> &digits)
{
    int n = digits.size();

    priority_queue<int, vector<int>, greater<int>> oneleft, twoleft, zeroleft;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (digits[i] % 3 == 0)
        {
            zeroleft.push(digits[i]);
        }
        else if (digits[i] % 3 == 1)
        {
            oneleft.push(digits[i]);
        }
        else
        {
            twoleft.push(digits[i]);
        }

        sum += digits[i];
    }

    if (sum % 3 == 1)
    {
        if (!oneleft.empty())
        {
            oneleft.pop();
        }
        else if (twoleft.size() >= 2)
        {
            twoleft.pop();
            twoleft.pop();
        }
        else
        {
            return "";
        }
    }
    else if (sum % 3 == 2)
    {
        if (twoleft.size() > 0)
        {
            twoleft.pop();
        }
        else if (oneleft.size() >= 2)
        {
            oneleft.pop();
            oneleft.pop();
        }
        else
        {
            return "";
        }
    }

    string ans = "";

    while (zeroleft.size() > 0)
    {
        ans += to_string(zeroleft.top());

        zeroleft.pop();
    }

    while (oneleft.size() > 0)
    {
        ans += to_string(oneleft.top());

        oneleft.pop();
    }

    while (twoleft.size() > 0)
    {
        ans += to_string(twoleft.top());

        twoleft.pop();
    }

    sort(ans.rbegin(), ans.rend());

    ans.erase(0, min(ans.find_first_not_of('0'), ans.size() - 1));

    return ans;
}

int main()
{

    vector<int> digits = {0, 0, 0, 0, 0};

    cout << largestMultipleOfThree(digits) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥