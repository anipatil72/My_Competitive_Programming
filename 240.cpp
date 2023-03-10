#include <bits/stdc++.h>
using namespace std;

long solve(string A)
{

    while (*(A.begin()) == ' ')
    {
        A.erase(A.begin());
    }

    while (A[A.length() - 1] == ' ')
    {
        A.erase(A.end() - 1);
    }

    int n = A.size();

    vector<int> a;

    if (n == 0)
    {
        return 0;
    }

    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] >= '0' && A[i] <= '9')
        {
            string t = "";

            while (A[i] >= '0' && A[i] <= '9' && i != n)
            {
                t += A[i];
                i++;
            }

            int g = stoll(t);

            sum += g;
        }
    }

    return sum;
}

int main()
{

    string s = "123";

    long b = solve(s);

    cout << b << endl;

    return 0;
}