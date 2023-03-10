#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//______________________CODE_BY_ANIRUDDHA_PATIL__________________________________

int main()
{

    int x;

    cin >> x;

    long long int odds = 0;
    int ans = 0;
    int num = 0;

    int minimum = INT_MAX;
    for (int i = 0; i < x; i++)
    {
        int temp;
        cin >> temp;
        if (temp & 1)
        {
            odds++;
        }

        else
        {
            if ((temp / 2) & 1)
            {
                ans++;
                odds++;
            }
            else
            {
                int k = 0;
                while ((temp & 1) == 0)
                {
                    temp >>= 1;
                    k++;
                }

                minimum = min(minimum, k);
                num++;
            }
        }
    }

    if (odds)
    {
        cout << ans + num << endl;
    }

    else
    {
        cout << minimum + num - 1 << endl;
    }

    return 0;
}