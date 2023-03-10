#include <bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int> &nums)
{

    int n = nums.size();

    long long a = 0, b = 0, c = 0, d = 0;

    c = n * (n + 1) / 2;

    b = n * (n + 1) * (2 * n + 1) / 6;

    for (int i = 0; i < n; i++)
    {
        a += nums[i] * nums[i];

        d += nums[i];
    }

    int e = (a - b) / (d - c);

    int m = (e + d - c) / 2;

    int p = (e + c - d) / 2;

    vector<int> ans = {m, p};

    return ans;
}

int main()
{

    return 0;
}