// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

#define M 1000000007
long long findTheArrayConcVal(vector<int> &nums)
{
    int n = nums.size();

    ll ans = 0;

    for (int i = 0; i <= n / 2; i++)
    {

        if (i == n / 2)
        {
            ans += nums[i];
        }
        else
        {
            ans += stoll(to_string(nums[i]) + to_string(nums[n - 1 - i]));
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥