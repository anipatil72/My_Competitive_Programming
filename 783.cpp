// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

vector<int> sortArray(vector<int> &nums)
{
    multiset<int> s;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        s.insert(nums[i]);
    }

    auto it = s.begin();

    for (int i = 0; i < n; i++)
    {
        nums[i] = *it;

        it++;
    }

    return nums;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥