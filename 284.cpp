#include <bits/stdc++.h>
using namespace std;

void recur(int &m, int &n, int &count, int &move, int x, int y, int &M)
{

    if (move == 0)
    {
        return;
    }

    if (x - 1 < 0)
    {
        count++;
        count = count % M;
    }

    if (x + 1 > n - 1)
    {
        count++;
        count = count % M;
    }

    if (y - 1 < 0)
    {
        count++;
        count = count % M;
    }

    if (y + 1 > m - 1)
    {
        count++;
        count = count % M;
    }

    if (x - 1 >= 0)
    {
        move--;
        recur(m, n, count, move, x - 1, y, M);
    }

    if (x + 1 < n)
    {
        move--;
        recur(m, n, count, move, x + 1, y, M);
    }

    if (y - 1 >= 0)
    {
        move--;
        recur(m, n, count, move, x, y - 1, M);
    }

    if (y + 1 < m)
    {
        move--;
        recur(m, n, count, move, x, y + 1, M);
    }
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{

    int count = 0;

    int M = 1000000007;

    recur(m, n, count, maxMove, startRow, startColumn, M);

    return count;
}

int main()
{

    int m = 2, n =2 , maxMove = 2;

    cout<<findPaths(m,n,2,0,0);

    return 0;
}