#include <bits/stdc++.h>
using namespace std;

void reNew(vector<int> &v)
{

    int n = v.size();

    int i = 0;

    while (v[i] < 0)
    {
        i++;
    }

    // cout<<i<<endl;

    for (int j = 0; j < i; j++)
    {

        int t = v[0];

        int k = 0;
        while ((k + 1) < n && abs(t) > abs(v[k + 1]))
        {
            swap(v[k], v[k + 1]);
            k++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        v[i] *= v[i];
    }
}

int main()
{

    int n ;

    cin>>n;



    vector<int> a(n,0);


    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    



    // vector<int> a = {-5, -2, -1, 0, 2, 5, 8, 9, 10, 11};

    reNew(a);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}