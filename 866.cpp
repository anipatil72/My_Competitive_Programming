// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

bool is_possible_to_get_seats(int n, int m, vector<int> &seats)
{
    int available_seats = 0;
    for (int i = 0; i < m; i++)
    {
        int prev = i == 0 ? 0 : seats[i - 1];
        int next = i == m - 1 ? 0 : seats[i + 1];
        if (prev + next + seats[i] == 0)
        {
            available_seats++;
            i++;
        }
    }

    return available_seats >= n;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥