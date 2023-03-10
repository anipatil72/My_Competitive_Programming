#include <bits/stdc++.h>
using namespace std;

bool feasible(vector<int> &a, int B, int ans)
{
    int count = 1, sum = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] > ans)
        {
            count++;
            sum = a[i];
        }
        else
        {
            sum = sum + a[i];
        }
    }
    return (count <= B);
}


int books(vector<int> &a, int B)
{
    int n = a.size();
    int max = a[0];
    int sum1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
        sum1 = sum1 + a[i];
    }
    if (B == 1)
    {
        return sum1;
    }
    if (B > n)
    {
        return -1;
    }
    int low = max, high = sum1, res;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (feasible(a, B, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{

    return 0;
}