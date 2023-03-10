#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> &nums)
{

    int n = nums.size();

    int x = 0;

    for (int i = 0; i < n; i++)
    {
        x = x ^ nums[i];
    }

    int k = 0;

    for (int i = 0; i < 31; i++)
    {
        if ((x & (1 << i)) > 0)
        {
            k = i;

            break;
        }
    }

    int t = 1 << k;

    int a = 0, b = 0;

    for (int i = 0; i < n; i++)
    {
        if ((t & nums[i]) > 0)
        {
            a = a ^ nums[i];
        }
        else
        {
            b = b ^ nums[i];
        }
    }

    return {a, b};
}

int main()
{

    vector<int> v = {1, 2, 1, 3, 2, 5, 5, 7};

    vector<int> ans = singleNumber(v);

    for (int i = 0; i < 2; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}