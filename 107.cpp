#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{

    int n = nums.size();
    int count = nums.size();

    for (int i = 0; i < n; i++)
    {

        int j = i + 1;

        while (nums[i] == nums[j])
        {
            // cout << "I am here!" << endl;
            nums.erase(nums.begin() + j);
            // cout << "The value of i " << i << " and the value pf j " << j << endl;
            count--;
        }

        n = nums.size();
    }

    return count;
}

int main()
{

    vector<int> v = {1, 1, 1, 1, 1, 4, 4, 7, 9, 9, 9, 11, 15, 15, 22, 22, 33, 33, 56};

    // v.erase(v.begin() + 2);

    int ans = removeDuplicates(v);

    cout << "The size of the array is " << ans << endl;

    for (int i = 0; i < ans; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}