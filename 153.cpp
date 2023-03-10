#include <bits/stdc++.h>
using namespace std;

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

vector<int> primesum(int n)
{

    vector<int> ans;

    if (n == 4)
    {
        ans.push_back(2);
        ans.push_back(2);

        return ans;
    }

    if (isPrime(n - 2))
    {
        ans.push_back(2);
        ans.push_back(n - 2);
        return ans;
    }

    if (isPrime(n - 3))
    {
        ans.push_back(3);
        ans.push_back(n - 3);
        return ans;
    }

    for (int i = 5; i * i <= n / 2; i += 6)
    {

        if (isPrime(n - i))
        {

            ans.push_back(i);
            ans.push_back(n - i);
            break;
        }

        if (isPrime(n - i - 2))
        {

            ans.push_back(i + 2);
            ans.push_back(n - i - 2);
            break;
        }
    }

    return ans ;
}

int main()
{

    vector<int> a = primesum(14);

    for (int i = 0; i < a.size(); i++)
    {
            cout<<a[i]<<" ";
    }
    

    return 0;
}