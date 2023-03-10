#include <bits/stdc++.h>
using namespace std;

int SingleNumber(vector<int> &A)
{
    int k, ans = 0;
    for (int j = 0; j < 32; j++)
    {
        k = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] & (1 << j))
            {
                k++;
            }
        }
        ans = ans + ((k % 3) * (1 << j));
    }
    return ans;
}

int main()
{

    return 0;
}