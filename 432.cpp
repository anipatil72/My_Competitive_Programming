#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin >> n;

    string s;

    cin >> s;

    int ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            int f, l;

            f = i, l = i + 1;

            int count = 0;

            while (l < n && s[f] == s[l])
            {
                l++;
                count++;
            }

            // cout<<count<<endl;

            i = l - 1;

            ans += count;
        }
    }

    cout << ans << endl;

    return 0;
}