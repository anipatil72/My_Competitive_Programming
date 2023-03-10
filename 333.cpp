#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int> &A, int B, int C)
{

    int n = A.size();

    int up = 0 , down = B-1,left = 0 , right = C-1;

    vector<vector<int>> v ;

    for (int i = 0; i < B; i++)
    {
        vector<int> row(C,0);

        v.push_back(row);
    }

    int k = 0 ;

    while (k<n)
    {
        for (int i = left; i <= right&&k<n; i++)
        {

            v[up][i] = A[k];
            k++;
                
        }

        up++;
        
        for (int i = up; i <= down&&k<n; i++)
        {

            v[i][right] = A[k];
            k++;
                
        }

        right--;
        
        for (int i = right; i >= left&&(k<n); i--)
        {

            v[down][i] = A[k];
            k++;
                
        }

        down--;
        
        
        for (int i = down; i >= up&&(k<n); i--)
        {

            v[i][left] = A[k];
            k++;
                
        }

        left++;
        
    }
    

    return v;


}

int main()
{

    vector<int> a = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    vector<vector<int>> ans = solve(a,4,4);

    for (int i = 0; i < ans.size(); i++)
    {

        for (int j = 0; j < ans[0].size(); j++)
        {
              cout<<ans[i][j]<<" ";  
        }

        cout<<endl;
        
            
    }
    

    return 0;
}