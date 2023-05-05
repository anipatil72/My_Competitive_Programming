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

bool isVowel(char d)
{
    return d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u';
}

int maxVowels(string s, int k)
{
    int n = s.length();

    int count = 0;

    int ans = 0;

    for (int i = 0; i < k; i++)
    {
        if (isVowel(s[i]))
        {
            count++;
        }
    }

    ans = max(ans, count);

    for (int i = k; i < n; i++)
    {
        if (isVowel(s[i]))
        {
            count++;
        }

        if (isVowel(s[i - k]))
        {
            count--;
        }

        ans = max(ans, count);
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥