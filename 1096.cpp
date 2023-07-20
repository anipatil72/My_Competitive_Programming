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

vector<int> asteroidCollision(vector<int> &arr)
{
    int n = arr.size();

    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            s.push(arr[i]);
        }
        else
        {
            if ((s.top() * 1LL * arr[i] > 0) || (s.top() < 0 && arr[i] > 0))
            {
                s.push(arr[i]);
            }
            else if (abs(s.top()) < abs(arr[i]))
            {

                bool a = 0, b = 0;

                while (!s.empty())
                {

                    if ((s.top() * 1LL * arr[i] > 0) || (s.top() < 0 && arr[i] > 0))
                    {
                        s.push(arr[i]);

                        break;
                    }
                    else if (abs(s.top()) < abs(arr[i]))
                    {
                        s.pop();

                        if (s.empty())
                        {
                            a = 1;
                            /* code */
                        }
                    }
                    else if (abs(s.top()) == abs(arr[i]))
                    {
                        s.pop();

                        if (s.empty())
                        {
                            b = 1;
                        }

                        break;
                    }
                    else
                    {
                        break;
                    }
                }

                if (s.empty() && a)
                {
                    s.push(arr[i]);
                }
            }
            else if (abs(s.top()) == abs(arr[i]))
            {
                s.pop();
            }
        }
    }

    vector<int> ans;

    while (!s.empty())
    {
        ans.push_back(s.top());

        s.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥