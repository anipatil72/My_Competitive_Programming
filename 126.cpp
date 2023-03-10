#include <bits/stdc++.h>
using namespace std;

int maximumGap(const vector<int> &arr)
{
    int n = arr.size();
    int lmin[n], rmax[n];
    int ans = -1;
    lmin[0] = arr[0];
    rmax[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        lmin[i] = min(lmin[i - 1], arr[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        rmax[i] = max(rmax[i + 1], arr[i]);
    }
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (lmin[i] <= rmax[j])
        {
            ans = max(ans, j - i);
            j++;
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

    vector<int> a = {1,2,3};

    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i)
    {
        cout<<a[i]<<" ";
    }



    return 0;
}
