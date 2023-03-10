#include <bits/stdc++.h>
using namespace std;

int RemoveMin(vector<int> &v)
{

    if (v.empty())
    {
        return -1;
    }

    int ans = v[0];
    int c1, c2, p;

    v[0] = v[v.size() - 1];
    v.pop_back();
    int lastIndex = v.size() - 1;
    p = 0;

    c1 = 2 * p + 1;
    c2 = 2 * p + 2;

    while (c1 <= lastIndex)
    {
        if (v[p] > v[c1] || v[p] > v[c2])
        {

            if (v[c1] < v[c2])
            {
                int t = v[p];
                v[p] = v[c1];
                v[c1] = t;
                p = c1;
                c1 = 2 * p + 1;
                c2 = 2 * p + 2;

                continue;
            }

            if (v[c2] < v[c1])
            {
                int t = v[p];
                v[p] = v[c2];
                v[c2] = t;
                p = c2;
                c1 = 2 * p + 1;
                c2 = 2 * p + 2;

                continue;
            }
        }
        break;
    }

    return ans;
}

void HeaPInsert(vector<int> &v)
{
    int p, c1, c2;

    for (int i = 0; i < v.size(); i++)
    {
        c1 = i;
        p = (c1 - 1) / 2;

        while (p >= 0)
        {
            if (v[p] > v[c1])
            {
                int t = v[p];
                v[p] = v[c1];
                v[c1] = t;

                c1 = p;
                p = (c1 - 1) / 2;
                continue;
            }

            break;
        }
    }
}

int main()
{

    vector<int> v = {2,6 ,8 ,5 ,4, 3};
    HeaPInsert(v);

    // v[3] = 100;

    // for (int i = 0; i < v.size(); i++)
    // {

    //     cout << v[i] << " ";
    // }

    // cout << endl;

    while (!v.empty())
    {
        cout << RemoveMin(v) << " ";
    }

    return 0;
}