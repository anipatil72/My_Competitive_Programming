#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin >> n;

    int a[7];

    for (int i = 0; i < 7; i++)
    {
        cin >> a[i];
    }

    int cur = n;

    int index = 0;

    while (cur > 0)
    {

        cur -= a[index];

        if (cur<=0)
        {
            break;
        }
        

        index++;

        if (index == 7)
        {
            index = 0;
        }
    }

    cout << index + 1 << endl;

    return 0;
}