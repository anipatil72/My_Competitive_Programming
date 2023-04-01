// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

ll k;

vector<ll> a, b, c;

vector<vector<ll>> multiplyMatrices(vector<vector<ll>> A, vector<vector<ll>> B)
{
    int n = A[0].size();

    int n1 = A.size();

    int n2 = B[0].size();

    int m = B.size();

    if (n != m)
    {
        return {{}};
    }

    vector<vector<ll>> ans(n1, vector<ll>(n2));

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            ll prod = 0;

            for (int k = 1; k <= n; k++)
            {
                prod += (A[i][k] * B[k][j]);
            }

            ans[i][j] = prod;
        }
    }

    return ans;
}

vector<vector<ll>> powerFunction(vector<vector<ll>> A, ll n)
{
    // Base Case

    if (n == 1)
    {
        return A;
    }

    // Power is Odd

    if (n & 1)
    {
        return multiplyMatrices(A, powerFunction(A, n - 1));
    }
    else
    {
        vector<vector<ll>> mat = powerFunction(A, n / 2);

        return multiplyMatrices(mat, mat);
    }
}

ll compute(ll n)
{

    // Base case
    if (n == 0)
    {
        return 0;
    }

    if (n <= k)
    {
        return b[n - 1];
    }

    // Otherwise do Matrix Exponentiation

    vector<ll> F1(k + 1);

    vector<vector<ll>> f1(k + 1, vector<ll>(1));

    for (int i = 1; i <= k + 1; i++)
    {
        f1[i][0] = F1[i];
    }

    // indexing from 1

    // Step 1

    for (int i = 1; i <= k; i++)
    {
        F1[i] = b[i - 1];
    }

    // Step 2 : Building Transformation Matrix

    vector<vector<ll>> T(k + 1, vector<ll>(k + 1));

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i < k)
            {
                if (j == i + 1)
                {
                    T[i][j] = 1;
                }
                else
                {
                    T[i][j] = 0;
                }
            }
            else
            {
                T[i][j] = c[k - j];
            }
        }
    }

    // Step 3 : Power function

    vector<vector<ll>> T_n = powerFunction(T, n - 1);

    vector<vector<ll>> Fn = multiplyMatrices(T_n, f1);

    return Fn[k][0];
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥