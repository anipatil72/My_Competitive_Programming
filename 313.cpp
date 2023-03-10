#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &A)
{
    int n = A.size();

    vector<int> v(3, 0);

    for (int i = 0; i < n; i++)
    {

        v[A[i]]++;
    }


    // cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;

    for (int i = 0; i < v[0]; i++)
    {
          A[i] = 0 ;  
    }

    for (int i = v[0]; i < v[1] + v[0]; i++)
    {
           A[i] = 1;
    }

    for (int i = v[1] + v[0]; i < n; i++)
    {
            A[i] = 2 ;
    }
    
    
    
}

int main()
{

    vector<int> v = {2, 1, 0, 2, 1, 1, 0, 2, 0, 2, 1, 1};

    sortColors(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}