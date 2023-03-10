#include <bits/stdc++.h>
using namespace std;

string solve(string A)
{

    int n = A.length();

    int i, j;

    bool b = true;

    if (n == 1)
    {
        return "-1";
    }

    int index;

    for (i = n - 1; i > 0; i--)
    {
        // if (A[i]<m)
        // {
        //     m = A[i];
        // }

        if (A[i] > A[i - 1])
        {

            index = i;
            break;
        }
    }

    if (i == 0 && n > 2)
    {
        return "-1";
    }

    if (n==2)
    {
            swap(A[0],A[1]);
            return A;
    }
    

    sort(A.begin() + index ,A.end());

    //cout<<index<<endl;

    auto it = upper_bound(A.begin() + i ,A.end(),A[index - 1]);

    //cout<<*it<<endl;

    int d = distance(A.begin(),it);

    swap(A[index -1],A[d]);

    //cout<<d<<endl;

    

    

    return A;
}

int main()
{

    string s = "15";

    // sort(s.begin(),s.end());

    // cout<<s<<endl;

    cout << solve(s) << endl;

    return 0;
}