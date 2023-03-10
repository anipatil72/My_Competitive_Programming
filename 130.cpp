#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &A, int B)
{

    int n = A.size();

    int sum = 0;
    int maxsum = INT_MIN;

    for (int i = 0; i < B; i++)
    {

        for (int j = 0; j < B - 1; j++)
        {
            sum = sum + A[i][j];
        }
    }

    for (int i = 0; i < n - B + 1; i++)
    {

        for (int j = 0; j < n - B + 1; j++)
        {

            for (int k = 0; k < B; k++)
            {
                sum = sum + A[k][j + B];
            }

            maxsum = max(maxsum, sum);
        }
    }
}

int solve(vector<vector<int>> &A, int B)
{
    int n = A.size();
    vector<vector<long long>> sum;
    for (int i = 0; i < n; i++)
    {
        long long rsum = 0;
        for (int j = 0; j < B; j++)
        {
            rsum += A[i][j];
        }
        vector<long long> temp;
        temp.push_back(rsum);
        for (int j = 1; j + B - 1 < n; j++)
        {
            rsum -= A[i][j - 1];
            rsum += A[i][j + B - 1];
            temp.push_back(rsum);
        }
        sum.push_back(temp);
    }
    long long ans = -1e18;
    for (int j = 0; j < sum[0].size(); j++)
    {
        long long isum = 0;
        for (int i = 0; i < B; i++)
        {
            isum += sum[i][j];
        }
        ans = max(ans, isum);
        for (int i = 1; i + B - 1 < n; i++)
        {
            isum -= sum[i - 1][j];
            isum += sum[i + B - 1][j];
            ans = max(isum, ans);
        }
    }
    return ans;
}

int main()
{

    return 0;
}