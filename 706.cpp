// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

int minimumRounds(vector<int> &tasks)
{
    int n = tasks.size();

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[tasks[i]]++;
    }

    int ops = 0;

    for (auto i = m.begin(); i != m.end(); i++)
    {

        int t = i->second;

        if (t == 1)
        {
            return -1;
        }

        if (t == 2 || t == 3)
        {
            ops += 1;

            continue;
        }

        int n3 = 1, n2 = 1;

        int rem3 = t / 3;

        rem3 *= 3;

        rem3 = t - rem3;

        if (rem3 == 1)
        {

            n3 = t / 3 - 1;

            n2 = 2;
        }
        else if (rem3 == 2)
        {
            n3 = t / 3;

            n2 = 1;
        }
        else if (rem3 == 0)
        {
            n3 = t / 3;

            n2 = 0;
        }

        ops += n3 + n2;
    }

    return ops;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥