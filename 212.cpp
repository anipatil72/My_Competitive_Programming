#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A)
{

    int n = A.size();

    if (n==1)
    {
            return 1 ;
    }
    

    int count = 0;

    int sum1 = 0, sum2 = 0;

    int evensum[n] = {0};
    int oddsum[n] = {0};



    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            sum1 += A[i];

            evensum[i] = sum1;
            oddsum[i] = sum2;
            continue;
        }

        sum2 += A[i];

        evensum[i] = sum1;
        oddsum[i] = sum2;
    }

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if ((evensum[i] - A[i] + sum2 - oddsum[i]) == (oddsum[i] + sum1 - evensum[i]))
            {
                count++;
            }
        }

        if (i % 2 == 1)
        {

            if ((evensum[i] + sum2 - oddsum[i]) == (oddsum[i] - A[i] + sum1 - evensum[i]))
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{

    vector<int> v = {5, 5, 2, 5, 8}; //  3 2 7 4 9 10

    cout << solve(v);

    return 0;
}