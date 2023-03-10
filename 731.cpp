// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

int main()
{

    vector<int> v = {3, 5, 9, 2, 8, 10, 11};

    int n = v.size();

    sort(v.begin(), v.end());

    int x = 17;

    int i = 0, j = n - 1;

    while (i < j)
    {
        if ((v[i] + v[j]) == x)
        {
            cout << "YES" << endl;
        }
        
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥