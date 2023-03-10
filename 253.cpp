#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(const vector<int> &A, int B)
{

    vector<int> v = {-1, -1};

    if (binary_search(A.begin(), A.end(), B))
    {
        int c, d;

        auto l = lower_bound(A.begin(), A.end(), B);
        auto h = upper_bound(A.begin(), A.end(), B);

        c = distance(A.begin(), l);
        d = distance(A.begin(), h);

        v[0] = c;

        v[1] = d - 1;
    }

    return v;
}

int main()
{

    vector<int> a = {5, 17, 100, 111};
    int b = 3;

    vector<int> ans = searchRange(a, b);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}