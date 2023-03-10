#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < m))
    {
        return true;
    }

    return false;
}

vector<int> nearestHotel(vector<vector<int>> &A, vector<vector<int>> &B)
{

    int n = A.size();

    int m = A[0].size();

    vector<pair<int, int>> hotels;

    vector<int> ans(B.size(),0);

    // for (int i = 0; i < B.size(); i++)
    // {
    //         queue<pair<int,int>> q;

    //         int dist = 0 ;

    //         q.push({B[i][0]- 1, B[i][1]-1});

    //         q.push({-1,-1});

    //         while (!q.empty())
    //         {
    //             pair<int,int> p = q.front();

    //             q.pop();

    //             if (p.first==-1&&p.second==-1)
    //             {
    //                     dist++;
    //                     continue;
    //             }

    //             if (A[p.first][p.second]==1)
    //             {
    //                   ans[i] = dist;
    //                   break;
    //             }

    //             if (isValid(p.first- 1, p.second, n,m))
    //             {
    //                  q.push({p.first - 1, p.second}) ;
    //             }
    //             if (isValid(p.first+1, p.second, n,m))
    //             {
    //                  q.push({p.first + 1, p.second}) ;
    //             }
    //             if (isValid(p.first, p.second + 1, n,m))
    //             {
    //                  q.push({p.first , p.second + 1}) ;
    //             }
    //             if (isValid(p.first, p.second - 1, n,m))
    //             {
    //                  q.push({p.first , p.second - 1}) ;
    //             }

    //         }

    // }

    // return ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 1)
            {
                hotels.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < B.size(); i++)
    {

        int m = INT_MAX;
        for (int j = 0; j < hotels.size(); j++)
        {

            int d = abs(B[i][0] - 1 - hotels[j].first) + abs(B[i][1] - 1 - hotels[j].second);
            m = min(m, d);


        }


        ans[i] = m;
    }

    return ans;
}

int main()
{

    vector<vector<int>> A =  {
                                {0, 0, 1},
                                {1, 1, 0}
                             };

vector<vector<int>> B =  
                            {
                            {1, 3},
                            {1, 1},
                            {1, 3},
                            {2, 2},
                            {1, 3}
                            };

    // vector<pair<int,int>> v = {{1,2},{3,4},{4,4}};


    vector<int> ans = nearestHotel(A,B);

    for (int i = 0; i < ans.size(); i++)
    {
            cout<<ans[i]<<" ";
    }
    

    return 0;
}