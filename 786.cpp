// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

long long minimumTime(vector<int> &time, int totalTrips)
{
    int n = time.size();

    vector<ll> pref(n);

    pref[0] = time[0];

    for (int i = 1; i < n; i++)
    {

        pref[i] = pref[i-1] + time[i];
            
    }

    auto it = upper_bound(pref.begin(), pref.end(), totalTrips);
    
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥