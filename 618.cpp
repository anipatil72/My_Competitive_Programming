#include <bits/stdc++.h>
using namespace std;

int hIndex(vector<int> &citations)
{

    int n = citations.size();

    // sort(citations.begin(), citations.end());

    for (int i = n; i > 0; i--)
    {
        auto it = lower_bound(citations.begin(), citations.end(), i);
        // auto itr = upper_bound(citations.begin(), citations.end(), i);

        if ((abs(distance(it, citations.end())) == i) )
        {
            return i;
        }
    }

    return 0;
}

int main()
{

    return 0;
}