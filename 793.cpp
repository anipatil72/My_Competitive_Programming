// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

vector<int> findMaxRow(vector<vector<int>> mat, int n)
{
    int pos = n - 1;

    int count = 0;

    int index = 0;

    for (int i = 0; i < n && pos >= 0; i++)
    {
        if (mat[i][pos] == 1)
        {

            while (pos >= 0)
            {
                count++;

                pos--;
            }

            index = i;
        }
    }

    return {count, index};
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥