#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B)
{

    int n = A.size();

    sort(A.begin(), A.end(), greater<int>());

    long sum = 0;

    int m = 0;

    int M = A[0];

    while (sum < B)
    {

        m++;
        for (int i = 0; i < n; i++)
        {
            if (A[i] > M - m)
            {
                sum++;

                if (sum == B)
                {
                    break;
                }
            }
        }
    }

    return M-m;
}

int main()
{

    vector<int> v = {4, 42, 40, 26, 46};

    int b = 20 ;


    cout<<solve(v,b);



    return 0;
}