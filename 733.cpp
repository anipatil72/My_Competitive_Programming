// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

void debug(vector<int> &temp)
{
    cout << "This is temp : " << endl;

    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }

    cout << endl;
}

bool myComp(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

bool isSorted(vector<int> &a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {

        if (a[i] > a[i + 1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<int> a(n);

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        mp[a[i]] = i;
    }

    if (m == 1 || isSorted(a))
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << "  ";
        }

        return 0;
    }

    set<int> s;

    s.insert(0);

    s.insert(n);

    int cur = 1;

    int count = m - 1;

    while (count > 0)
    {

        if (count > 0 && s.find(mp[cur]) == s.end())
        {

            s.insert(mp[cur]);

            count--;
        }

        if (count > 0 && s.find(mp[cur] + 1) == s.end())
        {
            s.insert(mp[cur] + 1);

            count--;
        }

        cur++;
    }

    vector<vector<int>> ans;

    vector<int> temp(s.begin(), s.end());

    for (int i = 0; i < temp.size() - 1; i++)
    {

        vector<int> t(a.begin() + temp[i], a.begin() + temp[i + 1]);

        // debug(t);

        ans.push_back(t);
    }

    sort(ans.begin(), ans.end(), myComp);

    for (int i = 0; i < ans.size(); i++)
    {

        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
    }

    cout << endl;

    // vector<vector<int>> ans = {{2, 1}, {5, 2, 7}, {0, 2, 1, 4, 3}};

    // sort(ans.begin(), ans.end());

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    // return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥