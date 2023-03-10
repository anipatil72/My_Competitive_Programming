#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A)
{

    int n = A.size();

    if (n <= 1)
    {
        return 1;
    }

    int i = 0, j = 1;
    while (i < n && j < n)
    {

        if (A[i] == A[j])
        {

            j++;

            continue;
        }

        if (j - i >= 2)
        {
            i+=2;
            A[i]= A[j];
            j++;
            continue;
           
        }

        i++;
        A[i] = A[j];

        



        j++;
    }

    if (A[n - 1] == A[n - 2])
    {
        i++;
        A[i] = A[i - 1];
    }

    return i + 1;
}

int main()
{
    vector<int> s = {1,1,1,1,2,2,2,2,3,4,4,4,5,6,6};

    int ans = solve(s);

    for (int i = 0; i < ans; i++)
    {
        cout << s[i] << " ";
    }

    return 0;
}