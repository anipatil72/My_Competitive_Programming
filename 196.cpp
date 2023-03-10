#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> v = {7, 10, 2, 1, 5, 6, 90, 34, 56, 0};

    int n = v.size();

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - 1; j++)
        {

            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}