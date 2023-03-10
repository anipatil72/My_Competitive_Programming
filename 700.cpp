// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();

    int m = mat[0].size();

    vector<vector<int>> ans(n, vector<int>(m));
    vector<vector<int>> visited(n, vector<int>(m, 1));

    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (mat[i][j] == 0)
            {

                pair<int, int> p = {i, j};

                q.push({p, 0});
            }
        }
    }

    while (!q.empty())
    {
        auto p = q.front();

        ans[p.first.first][p.first.second] = p.second;

        int x = p.first.first;

        int y = p.first.second;

        q.pop();

        visited[x][y] = 0;

        if (x > 0 && mat[x - 1][y] == 1 && visited[x - 1][y])
        {

            q.push({{x - 1, y}, p.second + 1});

            visited[x-1][y] = 0 ;

            // ans[x - 1][y] = p.second + 1;
        }

        if (x + 1 < n && mat[x + 1][y] == 1 && visited[x + 1][y])
        {

            q.push({{x + 1, y}, p.second + 1});
            visited[x+1][y] = 0 ;

            // ans[x + 1][y] = p.second + 1;
        }

        if (y > 0 && mat[x][y - 1] == 1 && visited[x][y - 1])
        {

            q.push({{x, y - 1}, p.second + 1});
            visited[x][y - 1] = 0 ;

            // ans[x][y - 1] = p.second + 1;
        }

        if (y + 1 < m && mat[x][y + 1] == 1 && visited[x][y + 1])
        {

            q.push({{x, y + 1}, p.second + 1});
            visited[x][y + 1] = 0 ;

            // ans[x][y + 1] = p.second + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    return ans;
}

int main()
{

    vector<vector<int>> matrix = {{0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0}};

    vector<vector<int>> ans = updateMatrix(matrix);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //         for (int j = 0; j < ans[0].size(); j++)
    //         {
    //                 cout<<ans[i][j]<<" ";
    //         }

    //         cout<<endl;
            
    // }
    



    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥