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

long long totalCost(vector<int> &costs, int k, int candidates)
{
    int n = costs.size();

    long long ans = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    int fir = 0, las = n - 1;
    int count = 0;

    while (fir <= las && count < candidates)
    {
        p.push({costs[fir], fir});

        fir++;

        if (fir <= las)
        {
            q.push({costs[las], las});

            las--;
        }

        count++;
    }

    for (int i = 0; i < k; i++)
    {

        if (p.size() != 0 && q.size() != 0)
        {
            pair<int, int> a = p.top(), b = q.top();

            if (a.first < b.first)
            {
                ans += a.first;

                p.pop();

                if (fir <= las)
                {
                    p.push({costs[fir], fir});

                    fir++;
                }
            }
            else if (a.first == b.first)
            {
                if (a.second < b.second)
                {
                    ans += a.first;

                    p.pop();

                    if (fir <= las)
                    {
                        p.push({costs[fir], fir});

                        fir++;
                    }
                }
                else
                {

                    ans += b.first;

                    q.pop();

                    if (fir <= las)
                    {
                        q.push({costs[las], las});

                        las--;
                    }
                }
            }
            else
            {
                ans += b.first;

                q.pop();

                if (fir <= las)
                {
                    q.push({costs[las], las});

                    las--;
                }
            }
        }
        else if (p.empty() && !q.empty())
        {
            pair<int, int> b = q.top();
            ans += b.first;

            q.pop();

            if (fir <= las)
            {
                q.push({costs[las], las});

                las--;
            }
        }
        else if (q.empty() && !p.empty())
        {
            pair<int, int> a = p.top();
            ans += a.first;

            p.pop();

            if (fir <= las)
            {
                p.push({costs[fir], fir});

                fir++;
            }
        }
        else
        {
            break;
        }
    }

    return ans;
}

int main()
{

    vector<int> rest = {17, 12, 10, 2, 7, 2, 11, 20, 8};

    int k = 3, candidates = 4;

    cout << totalCost(rest, k, candidates);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥