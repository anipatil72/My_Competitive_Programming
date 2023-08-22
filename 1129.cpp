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

bool repeatedSubstringPattern(string s)
{
    int n = s.length();

    string fol = s;

    auto fir = unique(fol.begin(), fol.end());

    if (n == 1)
    {
        return false;
    }

    if (abs(distance(fir, fol.begin())) == 1)
    {
        return true;
    }

    vector<int> des(26);

    for (int i = 0; i < n; i++)
    {
        des[s[i] - 'a']++;
    }

    int len = n + 1;

    for (int i = 0; i < 26; i++)
    {
        if (des[i] > 0)
        {
            len = min(des[i], len);
        }
    }

    if (len == 1)
    {
        return false;
    }

    if ((n % len) != 0)
    {
        return false;
    }

    int fin = n / len;

    string tem = s.substr(0, fin);

    cout << "This is tem : " << tem << endl;

    string ck = "";

    for (int i = 0; i < len; i++)
    {
        ck += tem;
    }

    cout << "This is ck : " << ck << endl;

    return ck == s;
}

// bool repeatedSubstringPattern(string s)
// {
//     int n = s.length();
//     for (int i = 1; i <= n / 2; i++)
//     {
//         if (n % i == 0)
//         {
//             string pattern = "";
//             for (int j = 0; j < n / i; j++)
//             {
//                 pattern += s.substr(0, i);
//             }
//             if (s == pattern)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

int main()
{

    string s = "a";

    cout << repeatedSubstringPattern(s) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥;