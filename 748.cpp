// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

template <int MOD>
class Modular
{
    // using ModInt = Modular<1'000'000'007>;
public:
    Modular(long long v = 0)
    {
        value = v % MOD;
        if (value < 0)
            value += MOD;
    }

    Modular(long long a, long long b) : value(0)
    {
        *this += a;
        *this /= b;
    }

    Modular &operator+=(Modular const &b)
    {
        value += b.value;
        if (value >= MOD)
            value -= MOD;
        return *this;
    }

    Modular &operator-=(Modular const &b)
    {
        value -= b.value;
        if (value < 0)
            value += MOD;
        return *this;
    }

    Modular &operator*=(Modular const &b)
    {
        value = (long long)value * b.value % MOD;
        return *this;
    }

    friend Modular power(Modular a, long long e)
    {
        Modular res = 1;
        while (e)
        {
            if (e & 1)
                res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }

    friend Modular inverse(Modular a)
    {
        return power(a, MOD - 2);
    }

    Modular &operator/=(Modular const &b)
    {
        return *this *= inverse(b);
    }

    friend Modular operator+(Modular a, Modular const b)
    {
        return a += b;
    }

    friend Modular operator-(Modular a, Modular const b)
    {
        return a -= b;
    }

    friend Modular operator-(Modular const a)
    {
        return 0 - a;
    }

    friend Modular operator*(Modular a, Modular const b)
    {
        return a *= b;
    }

    friend Modular operator/(Modular a, Modular const b)
    {
        return a /= b;
    }

    friend std::ostream &operator<<(std::ostream &os, Modular const &a)
    {
        return os << a.value;
    }

    friend std::istream &operator>>(std::istream &is, Modular &a)
    {
        is >> a.value;
        a.value %= MOD;
        if (a.value < 0)
            a.value += MOD;
        return is;
    }

    friend bool operator==(Modular const &a, Modular const &b)
    {
        return a.value == b.value;
    }

    friend bool operator!=(Modular const &a, Modular const &b)
    {
        return a.value != b.value;
    }

    friend Modular &operator++(Modular &a, int)
    {
        return a += 1;
    }

    friend Modular operator++(Modular const &a, int)
    {
        return Modular(a)++;
    }

    friend Modular &operator--(Modular &a, int)
    {
        return a -= 1;
    }

    friend Modular operator--(Modular const &a, int)
    {
        return Modular(a)--;
    }

    int value;
    static const int MOD_value = MOD;
};

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{
    int n = grid.size();

    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 1));

    vector<int> fir = {source.first, source.second, 0};
    vector<int> des = {destination.first, destination.second, 0};

    if (grid[des[0]][des[1]] == 0 || grid[fir[0]][fir[1]] == 0)
    {
        return -1;
    }

    queue<vector<int>> q;

    q.push(fir);

    while (!q.empty())
    {
        vector<int> cur = q.front();

        vis[cur[0]][cur[1]] = 0;

        q.pop();

        if (cur[0] == des[0] && cur[1] == des[1])
        {
            return cur[2];
        }

        if (cur[0] - 1 >= 0 && vis[cur[0] - 1][cur[1]] && grid[cur[0] - 1][cur[1]] == 1)
        {

            if (des[0] == cur[0] - 1 && des[1] == cur[1])
            {
                return cur[2] + 1;
            }

            q.push({cur[0] - 1, cur[1], cur[2] + 1});
        }

        if (cur[0] + 1 < n && vis[cur[0] + 1][cur[1]] && grid[cur[0] + 1][cur[1]] == 1)
        {

            if (des[0] == cur[0] + 1 && des[1] == cur[1])
            {
                return cur[2] + 1;
            }

            q.push({cur[0] + 1, cur[1], cur[2] + 1});
        }

        if (cur[1] - 1 >= 0 && (vis[cur[0]][cur[1] - 1]) && grid[cur[0]][cur[1] - 1] == 1)
        {
            if (des[0] == cur[0] && des[1] == cur[1] - 1)
            {
                return cur[2] + 1;
            }
            q.push({cur[0], cur[1] - 1, cur[2] + 1});
        }

        if (cur[1] + 1 < m && vis[cur[0]][cur[1] + 1] && grid[cur[0]][cur[1] + 1] == 1)
        {
            if (des[0] == cur[0] && des[1] == cur[1] + 1)
            {
                return cur[2] + 1;
            }
            q.push({cur[0], cur[1] + 1, cur[2] + 1});
        }
    }

    return -1;
}

int main()
{

    // vector<vector<int>> grid = {{1, 1, 1, 1},
    //                             {1, 1, 0, 1},
    //                             {1, 1, 1, 1},
    //                             {1, 1, 0, 0},
    //                             {1, 0, 0, 1}};

    // pair<int, int> source = {0, 1};
    // pair<int, int> destination = {2, 2};

    // cout << shortestPath(grid, source, destination);

    Modular<M> a(1, 2);

    cout<<a<<endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥