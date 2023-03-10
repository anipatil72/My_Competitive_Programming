#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &A)
{

    set<int> rows, cols;

    int m = A.size();

    int n = A[0].size();

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 0)
            {
                rows.insert(i);
                cols.insert(j);

            }
        }
    }

   
    if (!rows.empty())
    {
            
        for (auto i = rows.begin(); i != rows.end(); i++)
        {
            for (int j = 0; j < n; j++)
            {
                A[*i][j] = 0;
            }
        }
    }

    if (!cols.empty())
    {
                //cout<<n<<endl;
            
        for (auto i = cols.begin(); i != cols.end(); i++)
        {
            for (int j = 0; j < m; j++)
            {
               // cout<<j<<" "<<*i<<endl;
                A[j][*i] = 0;
            }
        }
    }
    
    


}

int main()
{

    vector<vector<int>> a ;
    setZeroes(a);


    for (int i = 0; i < a.size(); i++)
    {
            for (int j = 0; j < a[0].size(); j++)
            {

                cout<<a[i][j]<<" ";
                    
            }

            cout<<endl;
            
    }
    
   
    return 0;
}