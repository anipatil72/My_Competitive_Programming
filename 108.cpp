#include <bits/stdc++.h>
using namespace std;

vector<int> findPerm(const string A, int B)
{

    vector<int> v;

    int fn = 1, bn = B;

    for (int i = 0; i < B - 1; i++)
    {

        if (A[i] == 'D')
        {
            v.push_back(bn);
            bn--;
        }
        if (A[i] == 'I')
        {
            v.push_back(fn);
            fn++;
        }
    }

    v.push_back(fn);

    return v;
}

int main()
{

    vector<int> v = findPerm("DIDIDD", 7);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}