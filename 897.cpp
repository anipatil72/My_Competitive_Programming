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

// https://leetcode.com/problems/reducing-dishes/

int recur(int index, int order, vector<int> &satisfaction)
{
    int n = satisfaction.size();

    if (index >= n)
    {
        return 0;
    }

    int take = satisfaction[index] * order + recur(index + 1, order + 1, satisfaction);
    int nottake = recur(index + 1, order, satisfaction);

    return max(take, nottake);
}

int maxSatisfaction(vector<int> &satisfaction)
{

    int n = satisfaction.size();

    sort(satisfaction.begin(), satisfaction.end());

    int positive = (int)(satisfaction.end() - lower_bound(satisfaction.begin(), satisfaction.end(), 0));

    int sumpos = 0;

    int sumact = 0;

    int tem = n - 1;

    int mul = positive;

    if (satisfaction.back() <= 0)
    {
        return 0;
    }

    while (tem >= 0)
    {
        if (satisfaction[tem] < 0)
        {
            break;
        }
        else
        {

            sumpos += positive * satisfaction[tem];

            sumact += satisfaction[tem];

            tem--;

            positive--;
        }
    }

    if (tem < 0)
    {
        return sumpos;
    }

    while (tem >= 0 && ((satisfaction[tem] + sumact) >= 0))
    {
        sumact += satisfaction[tem];

        tem--;
    }

    tem++;

    int tess = 1;

    int fin = 0;

    for (int i = tem; i < n; i++)
    {
        fin += tess * satisfaction[i];

        tess++;
    }

    return fin;
}

int main()
{

    vector<int> v = {-1, -4, -5};

    cout << maxSatisfaction(v);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥