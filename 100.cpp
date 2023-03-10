#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A)
{
    sort(A.begin(), A.end());

    int n = A.size();
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        int j = i + 1 ;

        while (A[j]==A[i]&&j<n)
        {
            j++;
            cout<<"I am here!"<<endl;
        }
        
        cout<<i<<" "<<j<<endl;

        if (A[i] == n-j)
        {
            ans = 1;
            break;
        }
    }

    return ans;
}

int main()
{
    vector<int> v = {-4, -2, 0, -1, -6};

    cout << solve(v) << endl;

    return 0;
}