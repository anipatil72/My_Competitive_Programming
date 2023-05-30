// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

int cycleSortDistinct(vector<int> &a)
{
    int n = a.size();

    int miniswaps = 0;

    for (int cs = 0; cs < n - 1; cs++)
    {
        int des = 0;
        int item = a[cs];

        int pos = cs;

        for (int i = cs + 1; i < n; i++)
        {
            if (a[i] < item)
            {
                pos++;
            }
        }

        swap(item, a[pos]);

        des++;

        int tem = 0;

        while (pos != cs)
        {

            pos = cs;

            for (int i = cs + 1; i < n; i++)
            {
                if (a[i] < item)
                {
                    pos++;
                }
            }

            swap(item, a[pos]);

            des++;
        }

        miniswaps += des - 1;
    }

    return miniswaps;
}

int main()
{

    vector<int> a = {20, 40, 50, 10, 30};

    cout << cycleSortDistinct(a) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥