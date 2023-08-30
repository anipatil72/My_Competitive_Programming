#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_mex(const vector<int> &a)
{
    vector<bool> present(a.size() + 1, false);
    for (int x : a)
    {
        if (x < a.size() + 1)
        {
            present[x] = true;
        }
    }
    for (int i = 0; i < present.size(); ++i)
    {
        if (!present[i])
        {
            return i;
        }
    }
    return a.size();
}

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        while (k > 0)
        {
            int mex_val = find_mex(a);
            if (mex_val == n)
            {
                int new_val = (mex_val + a[mex_val % n]) / 2;
                if (find(a.begin(), a.end(), new_val) == a.end())
                {
                    a.push_back(new_val);
                    break;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (find(a.begin(), a.end(), mex_val) == a.end())
                {
                    a.push_back(mex_val);
                    k--;
                }
            }
        }

        cout << a.size() << endl;
        for (int x : a)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
