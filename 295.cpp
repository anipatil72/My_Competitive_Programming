#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A)
{

    int n = A.size();

    int m = 0;

    int i = 0, j = 0;

    while (i < n)
    {

        if (A[i] == 1)
        {
            j =  i;
            while (A[i] == A[j] && j < n)
            {
                j++;
            }

            m = max(m, j - i);

            i = j ;
        }

        i++;
    }


    return m ;
}

int main()
{


    vector<int> v = {2,2,2,3,4,5,5,5,3,3,8,9,0,4,2,0,8,1,1,1};

    cout<<solve(v);

    return 0;
}