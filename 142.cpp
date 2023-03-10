#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&A,int B)
{

    int n1 = A.size();

    int sum = 0;

    for (int i = n1 - B; i < n1; i++)
    {

        sum += A[i];
    }

    int best = sum;

    for (int i = n1 - B; i < n1; i++)
    {

        sum -= A[i];

        int k = (i + B) % n1;

        sum += A[k];


        //cout<<A[i]<<" "<<A[k]<<endl;

        best = max(best, sum);
    }

    return best;
}

int main()
{

    vector<int> a = {5, -2, 3, 1, 2};

    cout << solve(a, 3) << endl;

    return 0;
}