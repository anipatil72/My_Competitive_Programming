#include <bits/stdc++.h>
using namespace std;

string countAndSay(int A)
{

    string s = to_string(A);

    string ans = "";

    int count = 1;
    char number = s[0];

    int n = s.length();

    for (int i = 1; i < n; i++)
    {

        if ((s[i]) == number)
        {

            count++;
            continue;
        }

        ans += to_string(count) + number;

        number = s[i];
        count = 0;
    }

    //ans += to_string(count) + number;

    return ans;
}

int main()
{

  

    cout<<countAndSay(1211);

    return 0;
}