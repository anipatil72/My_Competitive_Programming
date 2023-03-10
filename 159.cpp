#include <bits/stdc++.h>
using namespace std;

int titleToNumber(string A)
{

    int ans = 0;

    int prod = 1;

    int n = A.length();

    for (int i = n - 1; i >= 0; i--)
    {
        ans += prod * (A[i] - 'A' + 1);
        prod = prod * 26;
    }

    return ans;
}

int main()
{

    string s = "B";

    cout << titleToNumber(s) << endl;

    return 0;
}