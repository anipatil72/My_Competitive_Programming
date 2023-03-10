#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long  n = 7263878756;

    int count = 0;

    while (n > 1)
    {
        if (n % 3 == 0 && n / 3 >= 1)
        {
            n = n / 3;
            count++;
            continue;
        }
        if (n % 2 == 0 && n / 2 >= 1)
        {
            n = n / 2;
            count++;
            continue;
        }

        n -= 1;
        count++;
    }

    cout << "The Minimum steps required are " << count << endl;

    return 0;
}