#include <bits/stdc++.h>
using namespace std;

int recur(vector<int> &v, int n, int sum)
{
    if (n == 0)
    {
        return (sum == 0) ? 1 : 0;
    }

    return recur(v,n-1,sum) + recur(v,n-1,sum - v[n-1]);
}

// void recur(vector<int> &v, int &count, int sum, int cur)
// {

//     if (sum < 0)
//     {
//         return;
//     }

//     if (sum == 0)
//     {
//         count++;
//         return;
//     }

//     int n = v.size();

//     for (int i = cur; i < n; i++)
//     {
//         recur(v, count, sum, i + 1);
//         recur(v, count, sum - v[i], i + 1);
//     }
// }

int main()
{

    vector<int> v = {10, 5, 2, 3, 6};

    int sum = 8;

    int n = v.size();

    // int cur = 0;

    int count = recur(v,n,sum);

    // for (int i = 0; i < v.size(); i++)
    // {
    //     // recur(v,count,sum, i + 1);
    //     recur(v, count, sum - v[i], i + 1);
    // }

    cout << count << endl;

    return 0;
}