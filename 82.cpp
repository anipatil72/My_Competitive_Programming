#include <bits/stdc++.h>
using namespace std;

int plusOne(vector<int> &A)
{

      int sum = INT_MIN/2;

    int best = INT_MIN/2;

    for (int i = 0; i < A.size(); i++)
    {
        sum = max(A[i], sum + A[i]);
        best = max(best, sum);
    }

    return best;
}

int main()
{

    vector<int> v = {-500};

    cout<<max(-500,-500 + INT_MIN);

   // cout << plusOne(v) << endl;

    //cout<<INT_MIN<<endl;

    return 0;
}