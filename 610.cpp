#include <bits/stdc++.h>
using namespace std;

#define ll long long

int findMaxConsecutiveOnes(vector<int> &s)
{

    ll n = s.size();

    ll a = 1, b = 1;
    ll at = 0, bt = 0;

    ll count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++)
    {

        if (s[i] == 0)
        {
            at++;

            b = max(b, bt);

            bt = 0;

            count1++;
        }
        else
        {
            bt++;

            a = max(a, at);

            at = 0;

            count2++;
        }
    }

    a = max(a, at);
    b = max(b, bt);

    return b;
}

int main()
{

    return 0;
}