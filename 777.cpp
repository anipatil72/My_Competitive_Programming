// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

int mostFrequentEven(vector<int> &nums)
{
    int n = nums.size();

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 == 0)
        {
            m[nums[i]]++;
        }
    }

    if (m.size() == 0)
    {
        return -1;
    }

    int ans = INT_MAX;

    int fre = INT_MIN;

    for (auto x : m)
    {

        if (x.second >= fre)
        {

            if (x.second == fre && ans > x.first)
            {
                fre = x.second;

                ans = x.first;
            }

            if (x.second > fre)
            {

                fre = x.second;

                ans = x.first;
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥