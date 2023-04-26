// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

int recur(int num)
{
    string tem = to_string(num);

    if (tem.length() == 1)
    {
        return num;
    }

    int sum = 0;

    int n = tem.length();

    for (int i = 0; i < n; i++)
    {
        sum += (tem[i] - '0');
    }

    return recur(sum);
}

int addDigits(int num)
{
    return recur(num);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥