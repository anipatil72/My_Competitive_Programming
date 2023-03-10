#include <bits/stdc++.h>
using namespace std;

int diffPossible(vector<int> &A, int B)
{

    int n = A.size();

    if (n == 1)
    {
        return 0;
    }

    if (B>(A[n-1]-A[0]))
    {
         return 0;   
    }
    

    int i = 0, j = 1;

    while (j < n)
    {
        if (A[j] - A[i] == B)
        {
            return 1;
        }

        if (A[j] - A[i] > B)
        {
            i++;

            if (i == j)
            {
                j++;
            }

            continue;
        }
        if (A[j] - A[i] < B)
        {

            j++;
        }
    }

    return 0;
}

int main()
{

    vector<int> v = {1,3,5};

    cout<<diffPossible(v,4);

    return 0;
}