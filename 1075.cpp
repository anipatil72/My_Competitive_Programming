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

int characterReplacement(string s, int k)
{
    int n = s.length();

    vector<int> pos(26, 0);

    int left = 0, right = 0;

    int ans = 0;

    while (right < n)
    {
        pos[s[right] - 'A']++;

        int des = *max_element(pos.begin(), pos.end());

        int tot = accumulate(pos.begin(), pos.end(), 0);

        int len = right - left + 1;

        pos[s[right] - 'A']--;

        if ((len - des) <= k)
        {
            pos[s[right] - 'A']++;

            right++;

            ans = max(ans, right - left);
        }
        else if (left < right)
        {
            pos[s[left] - 'A']--;

            left++;
        }
        else
        {
            left++;

            right++;
        }
    }

    return ans;
}

int main()
{

    string test = "AABABBA";

    int k = 0;

    cout << characterReplacement(test, k) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥