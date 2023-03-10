#include <bits/stdc++.h>
using namespace std;

int nTriang(vector<int> &A)
{

    sort(A.begin(), A.end());
    long ans = 0;
    int n = A.size();
    int k;

    for (int i = 0; i < n - 2; i++)
    {
        k = i + 2;
        for (int j = i + 1; j < n && A[i] != 0; j++)
        {
            while (k < n && (A[i] + A[j] > A[k]))
            {
                k++;
            }
            ans += (k - j - 1);
            ans %= 1000000007;
        }
    }
    return (int)ans;
}

int main()
{

    return 0;
}