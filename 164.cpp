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
// -------------------Important Notes------------------- //
// ***For Interactive Problems remember to remove multi test cases condition*** //
// (int)log2(x) + 1  -> to calculate number of bits of a number
// s.erase(0, min(s.find_first_not_of('0'), s.size()-1));   //for removing leading zero's
// Remember about unique function usage
// yi=(t|xi)⊕xi
// (int index = str.find(substr, pos)) != string::npos    // for checking substring 'substr' in string 'str'
// ((x >> j) & 1) ===> to check if the j-th bit is on/off
// x |= (1 << i) ===> to set the i-th bit on

void solve()
{

    int n, m, f, g, h, d, k;
    cin >> n >> m;

    vector<int> a;
    vector<int> x;

    for (int i = 0; i < n; i++)
    {
        cin >> d;

        a.push_back(d);
    }

    int startIndex = 0;

    int count = 1;

    for (int i = 1; i < n; i++)
    {

        if (a[i] == a[startIndex])
        {
            count++;

            if (count == m)
            {
                x.push_back(startIndex);
                count = 0;
                startIndex = i + 1;
            }

            continue;
        }

        startIndex = i;
    }











    

    //         a.insert(a.begin() + x[0] , m*a[x[0]]);
    //         a.erase(a.begin() + x[0] + 1 , a.begin() + x[0] + 1 + m);

    //         int prefix = 1 ;
    // for (int i = 1; i  < x.size(); i++)
    // {


    //         a.insert(a.begin() + x[i] - prefix*m + prefix, m*a[x[i] - prefix*m + prefix]);
    //         a.erase(a.begin() + x[i] + prefix - prefix*m, a.begin() + x[i] + prefix + m - prefix*m);

    //         prefix++ ;

    // }


    

   
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }

    // cin>>k;

    // for (int i = 0; i < k; i++)
    // {
    //         cin>>d;

    //         a.push_back(d);
    // }
}

int main()
{

    vector <int> v = {1,2,3,4,5,6,7};

    
    ll t;

    cin >> t;

    for (ll i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}