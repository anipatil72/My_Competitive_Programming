// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

long long digitsum(long long n)
{
    long long sum = 0, temp = n;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

long long makeIntegerBeautiful(long long n, int target)
{
    long long mul = 1, add = 0;
    while (digitsum(n + add) > target)
    {
        mul *= 10;
        add = mul - n % mul;
    }
    return add;
}

long long makeIntegerBeautiful0(long long n, int target)
{
    // string s = to_string(n);

    // int len = s.length();

    // string ans(len + 1, '0');

    // // // cout << ans << endl;
    // int sum = 0;

    // for (int i = 0; i < len; i++)
    // {
    //     sum += (s[i] - '0');
    // }

    // cout << "This is sum : " << sum << endl;

    // // int pos = 1;

    // // while (sum < target)
    // // {
    // //     sum += (s[pos] - '0' + 1);
    // //     pos++;
    // // }

    // if (sum <= target)
    // {
    //     return 0;
    // }

    // if ((((s[0] - '0') == 9)) || (s[0] - '0' + 1) > target)
    // {

    //     string tem(len, '0');

    //     string teem = "1" + tem;

    //     return stoll(teem) - n;
    // }

    // int pos = len;

    // cout << "This is pos : " << pos << " This is len : " << len << endl;

    // int carry = 0;

    // while (sum > target && (pos >= 0))
    // {

    //     sum -= ((s[pos] - '0' + carry) - 1);

    //     string temp = to_string(10 - (s[pos] - '0') - (carry));

    //     carry = 1;

    //     // cout << "This is temp : " << temp << endl;

    //     ans[pos] = temp[0];

    //     cout << "This is pos : " << pos << " this is ans : " << ans << "  and this is required sum :  " << sum << endl;

    //     pos--;
    // }

    // long long anss = stoll(ans);

    // string now = to_string(anss + n);

    // int check = 0;

    // for (int i = 0; i < now.length(); i++)
    // {
    //     check += (now[i] - '0');
    // }

    // if (check > target)
    // {
    //     string nos = "1";

    //     // cout << "I am here !" << endl;

    //     for (int i = 0; i < now.length(); i++)
    //     {
    //         nos += ('0');
    //     }

    //     return stoll(nos) - n;
    // }

    // return anss;
}

int main()
{

    cout << makeIntegerBeautiful(734504727, 10);

    return 0;
}

// 734504727
// 10

// ॥ जय श्री राम जय श्री कृष्ण ॥