#include <bits/stdc++.h>
using namespace std;

void reverseInGroups(vector<long long> &arr, int n, int k)
{

    int q = n / k;

    int cur = 0;

    for (int i = 0; i < q; i++)
    {

        for (int j = 0; j < k / 2; j++)
        {
            swap(arr[cur + j], arr[cur + k - j - 1]);
        }

        cur = cur + k;
    }

    for (int i = 0; i < (n - 1 - cur + 1) / 2; i++)
    {

        swap(arr[cur + i], arr[n - 1 - i]);
    }
}

int main()
{

    vector <long long> v = {1,2,3,4,5};

    reverseInGroups(v,5,3);



    for (int i = 0; i < v.size(); i++)
    {
          cout<<v[i]<<" ";  
    }
    

    return 0;
}