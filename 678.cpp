// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
using namespace std;

#define ll long long
// function to check prime
bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0)
        {
            return false;
        }
        if (n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

// Sieve of Erathosthenes
vector<bool> sieve(int n)
{
    vector<bool> v(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (v[i])
        {
            for (int j = i * i; j <= n; j = i + j)
            {
                v[j] = false;
            }
        }
    }
    return v;
}

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

ll GiveNcR(int n, int r)
{

    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;

    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;

            // gcd of p, k
            long long m = GCD(p, k);

            // dividing by gcd, to simplify
            // product division by their gcd
            // saves from the overflow
            p /= m;
            k /= m;

            n--;
            r--;
        }

        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }

    else
        p = 1;

    // if our approach is correct p = ans and k =1
    // cout << p << endl;

    return p;
}

ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {
        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;

        // Multiply 'a' with 2
        a = (a * 2) % mod;

        // Divide b by 2
        b /= 2;
    }

    // Return result
    return res % mod;
}

// A function to perform division of large numbers
string longDivision(string number, int divisor)
{
    // As result can be very large store it in string
    string ans;

    // Find prefix of number that is larger
    // than divisor.
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');

    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while (number.size() > idx)
    {
        // Store result in answer i.e. temp / divisor
        ans += (temp / divisor) + '0';

        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }

    // If divisor is greater than number
    if (ans.length() == 0)
    {
        return "0";
    }

    // else return ans
    {
        return ans;
    }
}

// Multiplies str1 and str2, and prints result.
string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    {
        return "0";
    }

    // will keep the result number in vector
    // in reverse order
    vector<int> result(len1 + len2, 0);

    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in num1
    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;

        // Go from right to left in num2
        for (int j = len2 - 1; j >= 0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';

            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

            // Carry for next iteration
            carry = sum / 10;

            // Store result
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
    {
        i--;
    }

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
    {
        return "0";
    }

    // generate the result string
    string s = "";

    while (i >= 0)
    {
        s += std::to_string(result[i--]);
    }

    return s;
}

string LCS(string &a, string &b)
{
    string ans = "";

    int m = a.length();
    int n = b.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i < m + 1; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 0; i < n + 1; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i < m + 1; i++)
    {

        for (int j = 1; j < n + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                // ans += a[i - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // for (int i = 0; i < m+1; i++)
    // {
    //         for (int j = 0; j < n+1; j++)
    //         {
    //                 cout<<dp[i][j]<<" ";
    //         }

    //         cout<<endl;

    // }

    int i = n, j = m;

    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            ans += a[i - 1];

            i--;
            j--;
        }

        else if (dp[i - 1][j] > dp[i][j - 1])
        {

            i--;
        }
        else
        {

            j--;
        }
    }

    // return dp[m][n];
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> LPS(string s)
{

    int n = s.length();

    vector<int> lps(n);

    lps[0] = 0;

    int len = 0;

    int i = 1;

    while (i < n)
    {
        if (s[len] == s[i])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }

    return lps;
}

vector<int> KMP(string &text, string &pattern)
{

    int n = text.length();
    int m = pattern.length();

    vector<int> ans;

    vector<int> lps = LPS(pattern);

    int i = 0, j = 0;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            ans.push_back(i - j);
            j = lps[j - 1];
        }

        if (i < n && text[i] != pattern[j])
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
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

void dfs(vector<vector<char>> &a, vector<vector<int>> &visited, ll &count, ll x, ll y, pair<ll, ll> root, ll bcount)
{
    visited[x][y] = 0;

    pair<ll, ll> cur = {x, y};

    // vector<vector<char>> visited2 = visited ;

    ll n = a[0].size();

    cout << "I am at : x = " << x << " and y = " << y << endl;

    count++;

    if (cur == root)
    {

        ll k = 0;

        if (x == 0)
        {

            if (1)
            {

                if (y < n - 1 && a[0][y + 1] == 'B' && visited[0][y + 1])
                {
                    // k++;

                    dfs(a, visited, count, 0, y + 1, root, bcount);
                }

                if (a[1][y] == 'B' && visited[1][y])
                {

                    // k++;

                    dfs(a, visited, count, 1, y, root, bcount);
                }

                if (count == bcount)
                {
                    cout << "YES" << endl;
                    return;
                }
            }

            count = 0;

            if (2)
            {

                if (y < n - 1 && a[0][y + 1] == 'B' && visited[0][y + 1])
                {
                    // k++;

                    dfs(a, visited, count, 0, y + 1, root, bcount);
                }

                if (y >= 1 && a[0][y - 1] == 'B' && visited[0][y - 1])
                {
                    //   k++;

                    dfs(a, visited, count, 0, y - 1, root, bcount);
                }

                if (count == bcount)
                {
                    cout << "YES" << endl;
                    return;
                }
            }

            count = 0;

            if (3)
            {

                if (y >= 1 && a[0][y - 1] == 'B' && visited[0][y - 1])
                {
                    //   k++;

                    dfs(a, visited, count, 0, y - 1, root, bcount);
                }

                if (a[1][y] == 'B' && visited[1][y])
                {

                    // k++;

                    dfs(a, visited, count, 1, y, root, bcount);
                }

                if (count == bcount)
                {
                    cout << "YES" << endl;
                    return;
                }
            }

            cout << "NO" << endl;

            return;

            // if (a[1][y] == 'B' && visited[1][y])
            // {

            //     // k++;

            //     dfs(a, visited, count, 1, y, root, bcount);
            // }

            // if (y < n - 1 && a[0][y + 1] == 'B' && visited[0][y + 1])
            // {
            //     // k++;

            //     dfs(a, visited, count, 0, y + 1, root, bcount);
            // }

            // if ( y >= 1 && a[0][y - 1] == 'B' && visited[0][y - 1])
            // {
            //     //   k++;

            //     dfs(a, visited, count, 0, y - 1, root, bcount);
            // }
        }
        else
        {

            if (1)
            {
                if (y < n - 1 && a[1][y + 1] == 'B' && visited[1][y + 1])
                {
                    // k++;

                    dfs(a, visited, count, 1, y + 1, root, bcount);
                }

                if (a[0][y] == 'B' && visited[0][y])
                {

                    // k++;

                    dfs(a, visited, count, 0, y, root, bcount);
                }

                if (count == bcount)
                {
                    cout << "YES" << endl;
                    return;
                }
            }

            count = 0;

            if (2)
            {

                if (y < n - 1 && a[1][y + 1] == 'B' && visited[1][y + 1])
                {
                    // k++;

                    dfs(a, visited, count, 1, y + 1, root, bcount);
                }

                if (y >= 1 && a[1][y - 1] == 'B' && visited[1][y - 1])
                {
                    //   k++;

                    dfs(a, visited, count, 1, y - 1, root, bcount);
                }

                if (count == bcount)
                {
                    cout << "YES" << endl;
                    return;
                }
            }

            count = 0;

            if (3)
            {

                if (a[0][y] == 'B' && visited[0][y])
                {

                    // k++;

                    dfs(a, visited, count, 0, y, root, bcount);
                }

                if (y >= 1 && a[1][y - 1] == 'B' && visited[1][y - 1])
                {
                    //   k++;

                    dfs(a, visited, count, 1, y - 1, root, bcount);
                }

                if (count == bcount)
                {
                    cout << "YES" << endl;
                    return;
                }
            }

            cout << "NO" << endl;

            return;
        }
    }
    else
    {

        if (x == 0)
        {

            if (a[1][y] == 'B' && visited[1][y])
            {

                // k++;

                dfs(a, visited, count, 1, y, root, bcount);
            }
            else if (y < n - 1 && a[0][y + 1] == 'B' && visited[0][y + 1])
            {
                // k++;

                dfs(a, visited, count, 0, y + 1, root, bcount);
            }
            else if (y >= 1 && a[0][y - 1] == 'B' && visited[0][y - 1])
            {
                //   k++;

                dfs(a, visited, count, 0, y - 1, root, bcount);
            }
        }
        else
        {

            if (a[0][y] == 'B' && visited[0][y])
            {

                // k++;

                dfs(a, visited, count, 0, y, root, bcount);
            }
            else if (y < n - 1 && a[1][y + 1] == 'B' && visited[1][y + 1])
            {
                // k++;

                dfs(a, visited, count, 1, y + 1, root, bcount);
            }
            else if (y >= 1 && a[1][y - 1] == 'B' && visited[1][y - 1])
            {
                //   k++;

                dfs(a, visited, count, 1, y - 1, root, bcount);
            }
        }
    }
}

void solve()
{
    ll n;

    cin >> n;

    vector<vector<char>> a(2, vector<char>(n));
    vector<vector<int>> visited(2, vector<int>(n, 1));

    ll bcount = 0;

    bool flag = true;

    ll x, y, p, q, r, s;

    for (ll i = 0; i < 2; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> a[i][j];

            if (a[i][j] == 'B')
            {
                bcount++;

                if (flag)
                {
                    x = i, y = j;
                    flag = false;
                }

                // x = i , y = j;
            }
        }
    }

    // bool twoway = false;

    // for (ll i = 0; i < n; i++)
    // {
    //     if (a[0][i] == 'B' && a[1][i] != 'B')
    //     {
    //         x = 0, y = i;

    //         break;
    //     }
    //     else if (a[1][i] == 'B' && a[0][i] != 'B')
    //     {
    //         x = 1, y = i;

    //         break;
    //     }
    //     else if (a[1][i] == 'B' && a[0][i] == 'B')
    //     {

    //         x = 0, y = i;

    //         break;
    //     }
    // }

    // if (a[1][i] == 'B')
    // {
    //     x = 1, y = i;

    //     break;
    //     // }
    // }

    ll count = 0;
    cout << "The ans is : ";

    dfs(a, visited, count, x, y, {x, y}, bcount);

    // if (count == bcount)
    // {
    //     cout << "YES" << endl;
    // }
    // else
    // {
    //     cout << "NO" << endl;
    // }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;

    cin >> t;

    for (ll i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥

// 1
// B
// B
// 1
// W
// B
// 1
// B
// W
// 2
// BB
// BB
// 2
// WB
// BB
// 2
// BB
// WB
// 2
// BW
// BB
// 2
// WW
// BB
// 2
// BW
// WB
// 2
// BB
// BW
// 2
// WB
// BW
// 2
// BB
// WW
// 3
// BBB
// BBB
// 3
// WBB
// BBB
// 3
// BBB
// WBB
// 3
// BWB
// BBB
// 3
// WWB
// BBB
// 3
// BWB
// WBB
// 3
// BBB
// BWB
// 3
// WBB
// BWB
// 3
// BBB
// WWB
// 3
// BBW
// BBB
// 3
// WBW
// BBB
// 3
// BBW
// WBB
// 3
// BWW
// BBB
// 3
// WWW
// BBB
// 3
// BWW
// WBB
// 3
// BBW
// BWB
// 3
// WBW
// BWB
// 3
// BBW
// WWB
// 3
// BBB
// BBW
// 3
// WBB
// BBW
// 3
// BBB
// WBW
// 3
// BWB
// BBW
// 3
// WWB
// BBW
// 3
// BWB
// WBW
// 3
// BBB
// BWW
// 3
// WBB
// BWW
// 3
// BBB
// WWW
// 4
// BBBB
// BBBB
// 4
// WBBB
// BBB...