#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &mat, int target)
{

    int m = mat.size();
    int n = mat[0].size();

    int low  = 0, high = m-1;

    int mid = (low + high)/2;

    while (low<high)
    {
        if (mat[low][n-1]==target)
        {
            return 1;    
        }
        if (mat[mid][n-1]==target)
        {
            return 1;    
        }
        if (mat[high][n-1]==target)
        {
            return 1;    
        }

        if (target>=mat[mid][0]&&target<mat[mid][n-1])
        {
               return binary_search(mat[mid].begin(),mat[mid].end(),target); 
        }

        if (target>=mat[low][0]&&target<mat[low][n-1])
        {
               return binary_search(mat[low].begin(),mat[low].end(),target); 
        }

        if (target>=mat[high][0]&&target<mat[high][n-1])
        {
               return binary_search(mat[high].begin(),mat[high].end(),target); 
        }
        

        if (target>mat[mid][n-1])
        {
             low = mid + 1;
            //  continue;   
        }


        if (target< mat[mid][n-1])
        {
             high = mid - 1;
            //  continue;   
        }

        mid = (low + high)/2; 
        
        
    }

    // cout<<low<<endl;
    // cout<<high<<endl;
    // cout<<mid<<endl;

    return binary_search(mat[mid].begin(),mat[mid].end(),target);
     
}

int main()
{
    // vector<int> v = {1,3,4,6,10,24,56,70,89};

      vector<vector<int>>  matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

      int target = 10;

      cout<<searchMatrix(matrix,target);

    // cout<<binary_search(v.begin(),v.end(),110);

    return 0;
}