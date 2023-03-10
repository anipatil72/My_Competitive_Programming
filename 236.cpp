#include <bits/stdc++.h>
using namespace std;

vector<int> Merge(vector<int> &a, vector<int> &b)
{

    int n = a.size() + b.size();

    vector<int> ans(n);

    merge(a.begin(), a.end(), b.begin(), b.end(), ans.begin());

    return ans;
}

vector<int> mergeSort(vector<int> &v)
{

    int n = v.size();

    if (n == 1)
    {

        return v;
    }

    if (n == 2)
    {
        if (v[0] > v[1])
        {
            swap(v[0], v[1]);
        }

        return v;
    }

    vector<int> x(v.begin(), v.begin() + n / 2);
    vector<int> y(v.begin() + n / 2, v.end());

    mergeSort(x);
    mergeSort(y);

    v = Merge(x, y);

    return v;
}

int main()
{

    vector<int> a = {2, 0, 9, -3, 1, 5, 23, 90, 45, 37, 21, 89,-100};

    vector<int> c = mergeSort(a);

    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}