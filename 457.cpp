#include <bits/stdc++.h>
using namespace std;

bool myComp(pair<int, int> p, pair<int, int> q)
{
    return p.second > q.second;
}

int minSetSize(vector<int> &arr)
{

    int n = arr.size();

    int target = n / 2;

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {

        m[arr[i]]++;
    }

    vector<pair<int, int>> v;

    for (auto i = m.begin(); i != m.end(); i++)
    {
        v.push_back({i->first, i->second});
    }

    int s = m.size();

    m.clear();

    sort(v.begin(), v.end(), myComp);

    int cur = 0;

    int j = 0;

    while (j < s && cur < target)
    {
        cur += v[j].second;

        j++;
    }

    return j;
}

int main()
{

    // vector<pair<int,int>> v = {{5,3},{2,2},{7,10},{3,4}};

    // sort(v.begin(),v.end(),myComp);

    // for (int i = 0; i < 4; i++)
    // {
    //         cout<<v[i].second<<" ";
    // }
    

    return 0;
}