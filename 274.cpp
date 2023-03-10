#include <bits/stdc++.h>
using namespace std;

int solve(string A)
{
    stack<char> s;

    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            s.push(A[i]);
            continue;
        }

        if (A[i] == ')' && s.top() == '(')
        {
            s.pop();
            continue;
        }

        s.push(A[i]);
    }


    return s.size();
}

int main()
{


    

    return 0;
}