// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define MOD 1000000007

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}

// returns map containing factor and multiplicity, Eg: 60 = {{2,2},{3,1},{5,1}}

map<long long, long long> factorize(long long n)
{
    map<long long, long long> ans;
    for (long long i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ans[i]++;
            n /= i;
        }
    }
    if (n > 1)
    {
        ans[n]++;
        n = 1;
    }
    return ans;
}

// -------------------Important Notes------------------- //
// ***For Interactive Problems remember to remove multi test cases condition*** //
// (int)log2(x) + 1  -> to calculate number of bits of a number
// s.erase(0, min(s.find_first_not_of('0'), s.size()-1));   //for removing leading zero's
// Remember about unique function usage
// yi=(t|xi)⊕xi
// (int index = str.find(substr, pos)) != string::npos    // for checking substring 'substr' in string 'str'
// ((x >> j) & 1) ===> to check if the j-th bit is on/off
// x |= (1 << i) ===> to set the i-th bit on

bool check(vector<int> &count)
{
    // bool ans = true;

    for (int i = 0; i < 3; i++)
    {

        if (count[i] < 1)
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    int n;

    string s;

    cin >> s;

    n = s.length();

    if (n <= 2)
    {
        cout << "0" << endl;

        return;
    }

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {

            a[i] = (i == 0 ? 0 : a[i - 1]) + 1;
        }
        else if (s[i] == '2')
        {

            b[i] = (i == 0 ? 0 : b[i - 1]) + 1;
        }
        else
        {

            c[i] = (i == 0 ? 0 : c[i - 1]) + 1;
        }
    }

    // int one = 0, two = 0, three = 0;

    vector<int> count(3, 0);

    count[s[0] - '0']++;
    count[s[1] - '0']++;
    count[s[2] - '0']++;

    if (check(count))
    {
            cout<<"3"<<endl;
            return ;
    }

    int mini = INT_MAX ;
    

    int left = 0, right = 2;

    while (right<n&&left + 2<right)
    {

        

        
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;

    cin >> t;

    for (ll i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥