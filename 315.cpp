#include <bits/stdc++.h>
using namespace std;

vector<int> countSmaller(vector<int> &nums)
{

    int n = nums.size();

    if (n == 1)
    {
        return {0};
    }

    // cout<<n<<endl;

    vector<int> v(n, 0);

    // for (int i = 0; i < n; i++)
    // {
    //         cout<<v[i]<<" ";
    // }
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
            count = 0;

        for (int j = i + 1; j < n; j++)
        {

            if (nums[j] < nums[i])
            {
                count++;
            }

            v[i] = count;
        }
    }

    return v;
}

int main()
{

    vector<int> a = {5, 2, 6, 1};

    vector<int> ans = countSmaller(a);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}