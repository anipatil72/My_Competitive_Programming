#include <iostream>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

int getTransformedLength(int n, int m)
{
    string s = to_string(n);
    int sizeIncrease = 0;

    for (int i = s.size() - 1; i >= 0 && m > 0; i--)
    {
        int opsNeeded = '9' - s[i];
        if (m >= opsNeeded)
        {
            m -= opsNeeded;
            s[i] = '9';
        }
        else
        {
            s[i] += m;
            m = 0;
            break;
        }
    }

    if (m > 0)
    {
        if (m % 10 == 0)
        {
            sizeIncrease = m / 10;
            m = 0;
        }
        else
        {
            sizeIncrease = m / 10;
            m = m % 10;
        }
    }

    // if there's a pending operation left, add it to the leftmost digit
    if (m > 0)
    {
        int leftmost = s[0] - '0' + m;
        s = to_string(leftmost) + s.substr(1);
    }

    return (s.size() + sizeIncrease) % MOD;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int num, m;
        cin >> num >> m;
        cout << getTransformedLength(num, m) << endl;
    }

    return 0;
}
