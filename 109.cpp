#include <bits/stdc++.h>
using namespace std;

int solve(int A, vector<int> &B)
{

    vector<int> p;
    int sum = 0;

    int ct = 0;

    for (int i = 0; i < A; i++)
    {
        sum = sum + B[i];
        p.push_back(sum);
    }

    for (int i = 1; i <= A - 2; i++)
    {
        for (int j = i + 1; j <= A - 1; j++)
        {

            int a = p[i - 1];
            int b = p[j - 1] - p[i - 1];
            int c = p[A - 1] - p[j - 1];
            if (a == b && b == c)
            {
                ct++;
            }
        }
    }

    return ct ;
}

int main()
{

    vector<int> v= {0, 1, -1, 0};

    cout<<solve(4,v);

    return 0;
}