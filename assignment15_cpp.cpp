// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

int main()
{

    ll n = 1431;

    vector<pair<string, ll>> regbook(1431);

    for (ll i = 0; i < n; i++)
    {
        ll roll;

        string HSS;

        string s;

        cin >> s;

        string temp = s.substr(0, 9);

        if (temp[5] == '5')
        {
            temp[3] = '1';
        }

        roll = stoll(temp);

        HSS = s.substr(10, 5);

        regbook[i] = {HSS, roll};

        // cout << roll << " " << HSS << endl;
    }

    sort(regbook.begin(), regbook.end());

    for (ll i = 0; i < n; i++)
    {
        string s = to_string(regbook[i].second);

        if (s[5] == '5')
        {
            s[3] = '2';
        }

        regbook[i].second = stoll(s);
    }

    for (ll i = 0; i < n; i++)
    {

        pair<string, ll> p = regbook[i];

        cout << p.first << "  " << p.second << " ";

        ll k, m;

        k = (regbook[i].second) / 1000;
        m = k % 100;
        // printf("  %d\n",m);
        if (m == 1)
        {
            printf("  CSE\n");
            continue;
        }
        if (m == 2)
        {
            printf("  ECE\n");
            continue;
        }
        if (m == 3)
        {
            printf("   ME\n");
            continue;
        }
        if (m == 4)
        {
            printf("   CE\n");
            continue;
        }
        if (m == 5)
        {
            printf("   DD\n");
            continue;
        }
        if (m == 6)
        {
            printf("   BSBE\n");
            continue;
        }
        if (m == 7)
        {
            printf("   CL\n");
            continue;
        }
        if (m == 8)
        {
            printf("   EEE\n");
            continue;
        }
        if (m == 21)
        {
            printf("   CST\n");
            continue;
        }
        if (m == 22)
        {
            printf("   EP\n");
            continue;
        }
        if (m == 23)
        {
            printf("   M&C\n");
            continue;
        }
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥