// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 100000
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    int n = M;

    if (start == end)
    {
        return 0;
    }

    vector<int> dis(n, (int)1e9);

    queue<pair<int, int>> q;

    q.push({start, 0});

    int a = arr.size();

    dis[start] = 0 ;

    // ll t = start;

    while (!q.empty())
    {

        pair<int, int> p = q.front();

        if (p.first == end)
            return p.second;

        q.pop();


        for (int i = 0; i < a; i++)
        {
           int temp = (p.first *1LL* arr[i])%M;

            // temp %= M;

            if (dis[temp] > p.second + 1)
            {

                dis[temp] = p.second + 1;
                q.push({temp, p.second + 1});
            }
        }
    }

    return 0;
}

int main()
{

    vector<int> arr = {2, 5, 7};
    int start = 3, end = 30;

    cout<<minimumMultiplications(arr, start, end);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥