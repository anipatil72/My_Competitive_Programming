#include <bits/stdc++.h>
using namespace std;

vector<int> subUnsort(vector<int> &A)
{

    int n = A.size();

    int p = INT_MIN, q = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            p = max(p, A[i]);
        }
    }

    for (int i = n - 1; i > 0; i--)
    {
        if (A[i] < A[i - 1])
        {
            q = min(q, A[i]);
        }
    }

    if (q == INT_MAX || p == INT_MIN)
    {
        return {-1};
    }
    else
    {

        for (int i = 0; i < n; i++)
        {
            if (A[i] > q)
            {
                q = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (A[i] < p)
            {
                p = i;
                break;
            }
        }
        return vector<int>{q, p};
    }
}

int main()
{

    vector<int> t = {1, 3, 2, 4, 5};

    return 0;
}