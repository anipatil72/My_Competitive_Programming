#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{

    int n = heights.size();

    if (n == 1)
    {
        return heights[0];
    }

    int i = 0, j = n - 1;

    int ans = INT_MIN;

    while (i <= j)
    {
        ans = max(ans, (j - i + 1) * (*min_element(heights.begin() + i, heights.begin() + j + 1)));

        // cout<<(*min_element(heights.begin() + i, heights.begin() + j))<<endl;

        if (heights[i] > heights[j])
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return ans;
}

int main()
{

    vector<int> v = {5, 5, 1, 7, 1, 1, 5, 2, 7, 6};

    cout << largestRectangleArea(v);

    return 0;
}