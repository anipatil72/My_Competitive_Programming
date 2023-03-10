#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A)
{

    int n = A.size();

    vector<int> v ;

    int count = 0 ;

    for (int i = 0; i < n; i++)
    {
       if (A[i]==0)
       {
            count++ ;
            continue;
       }

       v.push_back(A[i]);
             
    }


    for (int i = 0; i < count; i++)
    {
            v.push_back(0);
    }
    
    return v;
    
}

int main()
{

    vector<int> a = {1, 0, 0,2,0,1, 2, 0};

    vector<int> v = solve(a);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}