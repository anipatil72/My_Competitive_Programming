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

bool judgeCircle(string moves)
{
    int up = 0, downs = 0, left = 0, right = 0;

    int n = moves.length();

    for (int i = 0; i < n; i++)
    {
        if (moves[i] == 'L')
        {
            left++;
        }
        else if (moves[i] == 'R')
        {
            // right++;

            left--;
        }
        else if (moves[i] == 'U')
        {

            up++;
        }
        else if (moves[i] == 'D')
        {
            up--;
        }
    }

    return left == 0 && up == 0;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥