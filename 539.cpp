#include <bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int n = arr.size();

    priority_queue<pair<int,int>> q;

    for (int i = 0; i < k; i++)
    {
        q.push({abs(arr[i]-x), i});
    }

   
    

    for (int i = k; i < n; i++)
    {
        if (q.top().first > abs(arr[i] - x))
        {
            q.pop();
            q.push({abs(arr[i]-x), i});
        }
        else if (q.top().first == abs(arr[i] - x))
        {
            if (arr[q.top().second] > arr[i])
            {
                q.pop();
                q.push({abs(arr[i]-x), i});
            }
        }
    }

    vector<int> v;

    for (int i = 0; i < k; i++)
    {
        int d = arr[q.top().second];

        q.pop();

        v.push_back(d);
    }

    reverse(v.begin(),v.end());

    return v;
}

int main()
{

    return 0;
}