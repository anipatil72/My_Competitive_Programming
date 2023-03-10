#include <bits/stdc++.h>
using namespace std;

void partition(vector<int> &v, int b)
{
    int n = v.size();

    int i = 0, j = 0;

    while (j < n)
    {

        if (v[j] <= b)
        {
            swap(v[i], v[j]);
            i++;
        }

        j++;
    }
}

int main()
{

    vector<int> a = {23,14,20,10,20,10,20,10,20,10,20,10,8};

    partition(a, 10);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}