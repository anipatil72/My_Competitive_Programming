#include <bits/stdc++.h>
using namespace std;

bool checkIfExist(vector<int> &arr)
{

    int n = arr.size();

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if ((arr[i] != 0) && m.count(2 * arr[i]) > 0)
        {
            return 1;
        }

        if (arr[i] == 0 && m[0] >= 2)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{

    return 0;
}