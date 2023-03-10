#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{

    vector<int> num3;
    priority_queue<int, vector<int>, greater<int>> p;

    double ans;

    for (int i = 0; i < nums1.size(); i++)
    {
        p.push(nums1[i]);
    }

    for (int i = 0; i < nums2.size(); i++)
    {
        p.push(nums2[i]);
    }

    for (int i = 0; i < nums1.size() + nums2.size(); i++)
    {
        int f = p.top();
        num3.push_back(f);
        p.pop();
    }

    if (num3.size() % 2 == 0)
    {
        ans = ((double)num3[num3.size() / 2] + (double)num3[num3.size() / 2 - 1]) / 2;
    }

    if (num3.size() % 2 == 1)
    {
        ans = (double)num3[num3.size() / 2];
    }

    return ans;
}

int main()
{

    return 0;
}