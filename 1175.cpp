// #include <iostream>
// #include <vector>
// #include <string>
// #include <cstring>

// using namespace std;

// const int MAXN = 4001;

// vector<int> graph[MAXN];
// int subtreeSize[MAXN];
// string flags;
// int N;

// void dfs(int node, int parent, vector<int> &redNodes)
// {
//     subtreeSize[node] = 1;
//     if (flags[node - 1] == 'R')
//     {
//         redNodes.push_back(node);
//     }

//     for (int child : graph[node])
//     {
//         if (child != parent)
//         {
//             dfs(child, node, redNodes);
//             subtreeSize[node] += subtreeSize[child];
//         }
//     }
// }

// int solve(int start)
// {
//     vector<int> redNodes;
//     dfs(start, 0, redNodes);

//     int totalSize = subtreeSize[start];
//     int redCount = redNodes.size();

//     if (redCount % 2 == 0)
//     {
//         return totalSize;
//     }
//     else
//     {
//         int minSubtree = totalSize;
//         for (int redNode : redNodes)
//         {
//             minSubtree = min(minSubtree, subtreeSize[redNode]);
//         }
//         return totalSize - minSubtree;
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> N;

//     for (int i = 0; i < N - 1; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         graph[x].push_back(y);
//         graph[y].push_back(x);
//     }

//     cin >> flags;

//     for (int i = 1; i <= N; i++)
//     {
//         cout << solve(i) << "\n";
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 4001;

vector<int> graph[MAXN];
int subtreeSize[MAXN];
int dp[MAXN][2]; // dp[node][0] = max nodes reachable with even red flags, dp[node][1] = max nodes reachable with odd red flags
string flags;
int N;

void dfs(int node, int parent)
{
    subtreeSize[node] = 1;
    dp[node][0] = dp[node][1] = 0;

    if (flags[node - 1] == 'R')
    {
        dp[node][1] = 1;
    }
    else
    {
        dp[node][0] = 1;
    }

    for (int child : graph[node])
    {
        if (child != parent)
        {
            dfs(child, node);
            subtreeSize[node] += subtreeSize[child];

            int evenFromChild = dp[child][0];
            int oddFromChild = dp[child][1];

            // update dp for the current node
            dp[node][0] += max(evenFromChild, oddFromChild);
            dp[node][1] += evenFromChild;
        }
    }
}

int solve(int start)
{
    memset(subtreeSize, 0, sizeof(subtreeSize));
    memset(dp, 0, sizeof(dp));

    dfs(start, -1);

    return max(dp[start][0], dp[start][1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    cin >> flags;

    for (int i = 1; i <= N; i++)
    {
        cout << solve(i) << "\n";
    }

    cout << flags;
    return 0;
}
