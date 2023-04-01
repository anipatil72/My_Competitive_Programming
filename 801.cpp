// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

template <typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1)
{
    if (start < 0)
    {
        start = 0;
    }
    if (end < 0)
    {
        end = int(v.size());
    }

    for (int i = start; i < end; i++)
    {
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
    }
}

int odd(int i, int n)
{
    int left = i;

    int right = n - 1 - i;

    int ans = min(left, right) + 1;

    return ans;
}

int even(int i, int n)
{
    if (i == n - 1)
    {
        return 0;
    }

    int j = i + 1;

    int ans = min(abs(i), abs(n - 1 - j)) + 1;

    return ans;
}

long long countSubarray(int N, vector<int> A, int M)
{
    int n = N;

    int64_t ans = 0;

    sort(A.begin(), A.end());

    for (int i = 0; i < n; i++)
    {

        if (A[i] == M)
        {
            ans += (odd(i, n) + even(i, n));
        }
    }

    // cout << ans << endl;

    return ans;
}

int main()
{

    int n = 5, m = 2;

    vector<int> a = {2, 1, 3, 5, 4};

    vector<int> b = a;

    sort(b.begin(), b.end());

    cout << countSubarray(n, a, m) << endl;

    output_vector(b);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥