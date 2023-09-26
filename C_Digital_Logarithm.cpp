#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define mod 1000000007
#define inf 1000000000
#define N 200005
int t, n, a[N], b[N], cnt[15][15];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        bool flag = 1;
        for (int i = 1; i <= n; i++)
        {
            int x = log10(a[i]) + 1, y = log10(b[i]) + 1;
            cnt[x][y]++;
            if (x != y)
                flag = 0;
        }
        if (flag)
        {
            puts("0");
            continue;
        }
        bool flag2 = 0;
        for (int i = 1; i <= 9; i++)
            for (int j = 1; j <= 9; j++)
                if (cnt[i][j] && cnt[j][i])
                    flag2 = 1;
        if (flag2)
        {
            puts("2");
            continue;
        }
        puts("1");
    }
    return 0;
}
