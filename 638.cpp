// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &v)
{
    int n = v.size();

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 1; j < n; j++)
        {
            if (v[j] < v[j - 1])
            {
                swap(v[j], v[j - 1]);
            }
        }
    }
}

int main()
{

    vector<int> v = {2, 4, 1, 3};

    bubblesort(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥