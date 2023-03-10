#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int twocount = 0;
    bool turn = 1 ;

    int ansx, ansy;

    for (int i = 0; i < 8; i++)
    {
        // unordered_map<char,int> m;
        int hash_count = 0, dot_count = 0, lasthashindex;

        for (int j = 0; j < 8; j++)
        {
            char d;

            cin >> d;

            if (d == '#')
            {
                lasthashindex = j;
                hash_count++;
                if (hash_count == 2)
                {
                    twocount = 1;
                }
            }
        }

        if (hash_count==1 && twocount == 1&&turn)
        {
            // cout << i + 1 << " " << lasthashindex + 1 << endl;
            // return ;

            ansx = i + 1;
            ansy = lasthashindex + 1;
            turn = false;
        }
    }

    cout << ansx << " " << ansy << endl;
}

int main()
{

    int t;

    cin >> t;
    // scanf("\n");

    for (int i = 0; i < t; i++)
    {
        // scanf("\n");
        solve();
    }

    return 0;
}