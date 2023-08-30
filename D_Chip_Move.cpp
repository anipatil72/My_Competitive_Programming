#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> ways(n + 1, 0);
    ways[0] = 1;

    for (int x = 1; x <= n; x++)
    {
        int j = k;
        for (int dist = x - j; dist >= 0; dist = x - j)
        {
            ways[x] = (ways[x] + ways[dist]) % MOD;
            j++;
        }
    }

    for (int x = 1; x <= n; x++)
    {
        cout << ways[x] << " ";
    }

    return 0;
}
