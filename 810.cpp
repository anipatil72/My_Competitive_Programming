// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

void printvector(vector<int> &a)
{

    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

vector<int> lexicographicallyLargest(vector<int> &a, int n)
{

    int pos = 0;
    int parity = (a[0] % 2);

    int count = 0;

    int start = 0;

    while (pos < n)
    {

        if (a[pos] % 2 == parity)
        {

            count++;
        }
        else
        {
            sort(a.begin() + start, a.begin() + start + count, greater<int>());

            start = pos;

            parity = a[pos] % 2;

            count = 1;
        }
        pos++;
    }

    sort(a.begin() + start, a.begin() + start + count, greater<int>());

    return a;
}

int main()
{

    vector<int> a = {1, 3, 4, 1, 2};

    vector<int> ans = lexicographicallyLargest(a, 5);

    printvector(ans);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥