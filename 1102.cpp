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

string trim(string s)
{
}

int numDifferentIntegers(string word)
{
    int n = word.length();

    unordered_set<string> s;

    string num = "";

    for (int i = 0; i < n; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            if (num != "")
            {
                num.erase(0, min(num.find_first_not_of('0'), num.size() - 1));

                s.insert(num);

                num = "";
            }
        }
        else
        {
            num += word[i];
        }
    }

    if (num != "")
    {
        num.erase(0, min(num.find_first_not_of('0'), num.size() - 1));

        s.insert(num);

        num = "";
    }

    return s.size();
}

int main()
{

    string num = "00000";

    num.erase(0, min(num.find_first_not_of('0'), num.size() - 1));

    cout << num << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥