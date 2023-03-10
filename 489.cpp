#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin >> n;

    vector<vector<int>> v(n, vector<int>(2, 0));


    // map<int, vector<int>> m;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];

        
        // m[a].push_back(b);
    }

    int ans = 0;

    unordered_map<int,pair<int,int>> row ;
    unordered_map<int,pair<int,int>> col;

    for (int i = 0; i < n; i++)
    {
        int ml = INT_MAX, mr = INT_MIN, mu = INT_MIN, md = INT_MAX;
        
    }
    

    cout << ans << endl;

    return 0;
}