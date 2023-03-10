#include <bits/stdc++.h>
using namespace std;

vector<int> numsSameConsecDiff(int n, int k)
{

    vector<int> v;

    if (k == 0)
    {
        for (int i = 0; i < 9; i++)
        {
            string t = "";
            for (int j = 0; j < n; j++)
            {
                t += to_string(i + 1);
            }

            int temp = stoll(t);

            v.push_back(temp);
        }

        return v;
    }

    int i = 0;

    int j = i + k;

    string t = "";

    for (int l = 0; l < n; l++)
    {
        if (l % 2 == 0)
        {
            t += to_string(j);
        }
        else
        {
            t += to_string(i);
        }
    }

    v.push_back(stoll(t));

    t = "";

    i++;
    j++;

    while (j <= 9)
    {

        for (int l = 0; l < n; l++)
        {
            if (l % 2 == 0)
            {
                t += to_string(j);
            }
            else
            {
                t += to_string(i);
            }
        }

        v.push_back(stoll(t));

        t = "";

        for (int l = 0; l < n; l++)
        {
            if (l % 2 == 1)
            {
                t += to_string(j);
            }
            else
            {
                t += to_string(i);
            }
        }

        v.push_back(stoll(t));

        t = "";

        i++;
        j++;
    }

    i = 0;

    j = i + k;

    // int d = 9/(k + 1);

    while (i<=8&&k <= 4&&n>2)
    {

        int x = i;

        int count = 0;

        while (x <= 9)
        {
            count++;

            x += k;
        }

        x = i;

        if (count >= n)
        {
            string temp = "";
            for (int l = 0; l < n; l++)
            {
                temp += to_string(x);

                x += k;
            }

            if (temp[0] != '0')
            {
                v.push_back(stoll(temp));
            }

            reverse(temp.begin(), temp.end());

            if (temp[0] != '0')
            {

                v.push_back(stoll(temp));
            }

            // temp = "";
        }

        i++;
    }

    return v;
}

int main()
{

    return 0;
}