#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const char dir[4] = {'L', 'R', 'U', 'D'};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> maze(n);
    pair<int, int> start, end;

    for (int i = 0; i < n; ++i)
    {
        cin >> maze[i];
        for (int j = 0; j < m; ++j)
        {
            if (maze[i][j] == 'A')
                start = {i, j};
            if (maze[i][j] == 'B')
                end = {i, j};
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m, {-1, -1}));

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    bool found = false;
    while (!q.empty() && !found)
    {
        pair<int, int> curr = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && maze[nx][ny] != '#')
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
                prev[nx][ny] = curr;
                if (maze[nx][ny] == 'B')
                {
                    found = true;
                    break;
                }
            }
        }
    }

    if (!found)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        string path;
        while (end != start)
        {
            pair<int, int> before = prev[end.first][end.second];
            for (int i = 0; i < 4; ++i)
            {
                if (before.first + dx[i] == end.first && before.second + dy[i] == end.second)
                {
                    path += dir[i];
                    break;
                }
            }
            end = before;
        }
        reverse(path.begin(), path.end());
        cout << path.length() << endl;
        cout << path << endl;
    }

    return 0;
}
