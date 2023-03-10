#include <iostream>
#include <vector>

using namespace std;

int minN(long long int n)
{

    vector<int> a;
    vector<int> b;

    int i, j, k, l;

    while (n % 10 != 0)
    {

        int u = n % 10;
        b.push_back(u);
        n = n / 10;
    }

    int d = b.size();

    for (i = 0; i < d; i++)
    {
        a.push_back(b[d - 1 - i]);
    }

    if ((a.size() == 2))
    {

        return a[1];
    }

    int m = a[0], h1;
    if (a.size() > 2)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] < m)
            {
                m = a[i];
            }
        }
    }

    return m;
}

int main()
{

    int t, i;

    cin >> t;

    long long int p[t];

    for (i = 0; i < t; i++)
    {

        cin >> p[i];
    }

    for (i = 0; i < t; i++)
    {
        int y = minN(p[i]);

        cout << y << endl;
    }

    return 0;
}