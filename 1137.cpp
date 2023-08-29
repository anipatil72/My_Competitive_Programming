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

int bestClosingTime(string customers)
{
    int n = customers.length();

    int coms = 0;

    vector<int> till(n, 0);

    for (int i = 0; i < n; i++)
    {
        coms += (customers[i] == 'Y');

        till[i] = coms;
    }

    int noms = n - coms;

    int ans = 1000000;

    int index = -1;

    for (int i = 0; i <= n; i++)
    {
        int comstillhere = (i == 0 ? 0 : till[i - 1]);

        int nomstillhere = i - comstillhere;

        int comsafter = coms - comstillhere;

        int des = comsafter + nomstillhere;

        if (des < ans)
        {
            ans = des;

            index = i;
        }
    }

    return index;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥