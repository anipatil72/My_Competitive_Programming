// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

int minDeletionSize(vector<string> &strs)
{

    int n = strs.size();

    int m = strs[0].length();

    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {

            if (strs[j][i] > strs[j + 1][i])
            {

                count++;
            }
        }
    }

    return count;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥