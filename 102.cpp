#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t, f, g, l, a, b, c;

    cin >> t;


    vector<int> v;

    for (int i = 0; i < t; i++)
    {
    unordered_map<int, int> m;
        int n ;
        cin >> n;

        int eve_count = 0;

        for (int j = 0; j < n; j++)
        {
            int d ;
            cin >> d;
            m[d]++;
        }

        //cout<<m.size()<<endl;

        for (auto it = m.begin(); it != m.end(); it++)
        {

            if (it->second % 2 == 0)
            {
                eve_count++;
            }
        }

        if (eve_count % 2 == 0)
        {
            cout << m.size() << endl;
        }

        if (eve_count % 2 != 0)
        {
            cout << m.size() - 1 << endl;
        }
    }

    return 0;
}