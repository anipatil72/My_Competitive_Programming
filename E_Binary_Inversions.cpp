// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define MOD 1000000007
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

ll modu(string num, ll a)
{
    // Initialize result
    int res = 0;

    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
    {
        res = (res * 10 + (int)num[i] - '0') % a;
    }

    return res;
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

// ^^^^^^^^^^^^ MODULAR EXPO ^^^^^^^^^^^^^^

int modExp(int a, int b, int mod = MOD)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % mod;
        }
        a = (a * 1LL * a) % mod;
        b = b >> 1;
    }
    return ans;
}

// Multiplies str1 and str2, and prints result.
string multiplyStrings(string num1, string num2)
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

    vector<vector<ll>> dp(m + 1, vector<ll>(n + 1));

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

// Function to find Bit-wise & and | of all numbers from x to y.
int msbPos(ll n)
{
    int msb_p = -1;
    while (n)
    {
        n = n >> 1;
        msb_p++;
    }
    return msb_p;
}

// Function to find Bit-wise & of all numbers from x
// to y.
ll ANDofRange(ll x, ll y)
{
    ll res = 0; // Initialize result

    while (x && y)
    {
        // Find positions of MSB in x and y
        int msb_p1 = msbPos(x);
        int msb_p2 = msbPos(y);

        // If positions are not same, return
        if (msb_p1 != msb_p2)
            break;

        // Add 2^msb_p1 to result
        ll msb_val = (1LL << msb_p1);
        res = res + msb_val;

        // subtract 2^msb_p1 from x and y.
        x = x - msb_val;
        y = y - msb_val;
    }

    return res;
}

// Returns the Bitwise OR of all
// integers between L and R
long long int findBitwiseOR(long long int L, long long int R)
{
    long long int res = 0;

    // Find the MSB position in L
    int msb_p1 = msbPos(L);

    // Find the MSB position in R
    int msb_p2 = msbPos(R);

    while (msb_p1 == msb_p2)
    {
        long long int res_val = (1 << msb_p1);

        // Add this value until msb_p1 and
        // msb_p2 are same;
        res += res_val;

        L -= res_val;
        R -= res_val;

        // Calculate msb_p1 and msb_p2
        msb_p1 = msbPos(L);
        msb_p2 = msbPos(R);
    }
    // Find the max of msb_p1 and msb_p2
    msb_p1 = max(msb_p1, msb_p2);

    // Set all the bits from msb_p1 upto
    // 0th bit in the result
    for (int i = msb_p1; i >= 0; i--)
    {
        long long int res_val = (1 << i);
        res += res_val;
    }
    return res;
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

#define n_l '\n'
template <typename T, size_t N>
int SIZE(const T (&t)[N])
{
    return N;
}

template <typename T>
int SIZE(const T &t)
{
    return t.size();
}

string to_string(const string s, int x1 = 0, int x2 = 1e9)
{
    return '"' + ((x1 < s.size()) ? s.substr(x1, x2 - x1 + 1) : "") + '"';
}

string to_string(const char *s)
{
    return to_string((string)s);
}

string to_string(const bool b)
{
    return (b ? "true" : "false");
}

string to_string(const char c)
{
    return string({c});
}

template <size_t N>
string to_string(const bitset<N> &b, int x1 = 0, int x2 = 1e9)
{
    string t = "";
    for (int __iii__ = min(x1, SIZE(b)), __jjj__ = min(x2, SIZE(b) - 1); __iii__ <= __jjj__; ++__iii__)
    {
        t += b[__iii__] + '0';
    }
    return '"' + t + '"';
}

template <typename A, typename... C>
string to_string(const A(&v), int x1 = 0, int x2 = 1e9, C... coords);

int l_v_l_v_l = 0, t_a_b_s = 0;

template <typename A, typename B>
string to_string(const pair<A, B> &p)
{
    l_v_l_v_l++;
    string res = "(" + to_string(p.first) + to_string(p.second) + ")";
    l_v_l_v_l--;
    return res;
}

template <typename A, typename... C>
string to_string(const A(&v), int x1, int x2, C... coords)
{

    int rnk = rank<A>::value;
    string tab(t_a_b_s, ' ');

    string res = "";
    bool first = true;

    if (l_v_l_v_l == 0)
        res += n_l;
    res += tab + "[";

    x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v));
    auto l = begin(v);
    advance(l, x1);
    auto r = l;
    advance(r, (x2 - x1) + (x2 < SIZE(v)));

    for (auto e = l; e != r; e = next(e))
    {
        if (!first)
        {
            res += " ";
        }
        first = false;

        l_v_l_v_l++;
        if (e != l)
        {
            if (rnk > 1)
            {
                res += n_l;
                t_a_b_s = l_v_l_v_l;
            };
        }
        else
        {
            t_a_b_s = 0;
        }

        res += to_string(*e, coords...);
        l_v_l_v_l--;
    }
    res += "]";
    if (l_v_l_v_l == 0)
        res += n_l;
    return res;
}

void dbgm()
{
    ;
}
template <typename Heads, typename... Tails>
void dbgm(Heads H, Tails... T)
{
    cout << to_string(H) << " | ";
    dbgm(T...);
}
#define dbgm(...)                         \
    cout << "[" << #__VA_ARGS__ << "]: "; \
    dbgm(__VA_ARGS__);                    \
    cout << endl;

void solve()
{

    int n;

    cin >> n;

    vector<int> a(n);

    vector<int> pref1(n);
    vector<int> pref0(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    int cur1 = 0;
    int cur2 = 0;

    for (int i = 0; i < n; i++)
    {

        pref1[i] = cur1;

        pref0[i] = cur2;

        if (a[i] == 1)
        {
            cur1++;
        }
        else
        {
            cur2++;
        }
    }

    // dbgm(pref0, pref1);

    ll tot = 0;

    ll onecount = accumulate(a.begin(), a.end(), 0);

    ll zerocount = n - onecount;

    for (int i = 0; i < n; i++)
    {

        if (a[i] == 0)
        {
            tot += pref1[i];

            // cout << "I am adding : " << pref1[i] << " at " << i << endl;
        }
        else
        {

            tot += zerocount - pref0[i];
        }
    }

    // cout << "Tot is : " << tot << endl;

    tot /= 2;

    // dbgm(tot, zerocount, onecount);
    ll maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            // flippig this will make it one

            ll t = zerocount - 1 - pref0[i] - pref1[i];

            // cout << "I am adding : " << zerocount - 1- pref0[i] - pref1[i] << " at " << i << endl;
            // t /= 2;

            maxi = max(t, maxi);

            // tot = max(tot, tot + maxi);
        }
        else
        {
            // flipping this will make it zero

            ll t = pref1[i] - zerocount + pref0[i];
            // cout << "I am adding : " << pref1[i] - zerocount - pref0[i] << " at " << i << endl;
            // t /= 2;
            maxi = max(t, maxi);
            // tot = max(tot, tot + maxi);
        }
    }

    tot = max(tot, tot + maxi);

    // cout << "This is ans : " << endl;

    cout << tot << endl;
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