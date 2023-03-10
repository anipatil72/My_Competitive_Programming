#include <bits/stdc++.h>
using namespace std;

bool reorderedPowerOf2(int n)
{

    if ((n & (n - 1)) == 0)
    {
        return true;
    }

    string s = to_string(n);

    string org = s;

    // cout << s << endl;

    next_permutation(s.begin(), s.end());

    while (s != org)
    {
        if (s[0] == '0')
        {
            next_permutation(s.begin(), s.end());
            continue;
        }

        long long  a = stoll(s);

        if ((a & (a - 1)) == 0)
        {
            return true;
        }

        // cout<<a<<endl;
        next_permutation(s.begin(), s.end());
    }

    return false;
}

int main()
{

    bool ans = reorderedPowerOf2(23);

    cout<<"The answer is : "<<ans<<endl;

    // int a = 1024;

    // cout<<(a&(a-1))<<endl;

    return 0;
}