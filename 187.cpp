#include <bits/stdc++.h>
using namespace std;

int minMoves2(vector<int> &nums)
{

   int n = nums.size(), steps = 0;
        nth_element(nums.begin(), nums.begin()+(n/2), nums.end()); //Fixing ths median element
        int median = nums[n/2];
        for(int i=0; i<n; i++){
            steps += abs(nums[i] - median);
        }
        return steps;
}

int main()
{

    vector<int> v = {1, 2, 3};

    cout << minMoves2(v) << endl;

    return 0;
}