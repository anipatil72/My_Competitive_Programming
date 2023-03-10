#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, i, j, k;

    cin >> t;

    int an[t], bn[t];

    int r[t][2];

    for (i = 0; i < t; i++)
    {
        cin >> an[i];
        vector<int> a;

        for (j = 0; j < an[i]; j++)
        {
            int p;

            cin >> p;

            a.push_back(p);
        }

        cin >> bn[i];
        vector<int> b;

        for (j = 0; j < bn[i]; j++)
        {
            int p;

            cin >> p;

            b.push_back(p);
        }

        if (*max_element(a.begin(), a.end()) > *max_element(b.begin(), b.end()))
        {
            r[i][0] = 1;
            r[i][1] = 1;
        }

        if (*max_element(a.begin(), a.end()) ==*max_element(b.begin(), b.end()))
        {
            r[i][0] = 1;
            r[i][1] = 0;
        }

        if (*max_element(a.begin(), a.end()) < *max_element(b.begin(), b.end()))
        {
            r[i][0] = 0;
            r[i][1] = 0;
        }
    }

    for (i = 0; i < t; i++)
    {
        if (r[i][0] == 1)
        {
            cout << "Alice" << endl;
        }

        if (r[i][0] == 0)
        {
            cout << "Bob" << endl;
        }

        if (r[i][1] == 1)
        {
            cout << "Alice" << endl;
        }

        if (r[i][1] == 0)
        {
            cout << "Bob" << endl;
        }
    }

    return 0;
}