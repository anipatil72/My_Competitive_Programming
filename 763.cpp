// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

const int inf = (int)1e8;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    int n = edges.size();

    vector<int> dis(V, inf);

    dis[S] = 0;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {

            int fir = edges[j][0];
            int sec = edges[j][1];
            int weight = edges[j][0];

            if ((dis[fir] != inf) && (dis[sec] > dis[fir] + weight))
            {
                dis[sec] = dis[fir] + weight;

                if (i == V - 1)
                {
                    return {-1};
                }
            }
        }
    }

    return dis;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥