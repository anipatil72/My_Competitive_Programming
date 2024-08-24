#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxRides(vector<int> &left, vector<int> &right, long long money)
{
    int l = 0, r = 0;
    long long sum = 0;
    int maxRides = 0;
    int leftSize = left.size(), rightSize = right.size();

    // First, take as many rides from the right as possible
    while (r < rightSize && sum + right[r] <= money)
    {
        sum += right[r++];
    }
    maxRides = r;

    // Now, try adding rides from the left while removing from the right if necessary
    for (int i = 0; i < leftSize; i++)
    {
        sum += left[i];
        while (r > 0 && sum > money)
        {
            sum -= right[--r];
        }
        if (sum <= money)
        {
            maxRides = max(maxRides, i + 1 + r);
        }
        else
        {
            break;
        }
    }

    return maxRides;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int l, r;
        long long m;

        cin >> l;
        vector<int> left(l);
        for (int i = 0; i < l; i++)
        {
            cin >> left[i];
        }

        cin >> r;
        vector<int> right(r);
        for (int i = 0; i < r; i++)
        {
            cin >> right[i];
        }

        cin >> m;

        cout << maxRides(left, right, m) << "\n";
    }

    return 0;
}