#include <bits/stdc++.h>
using namespace std;

int searchMatrix(vector<vector<int>> &A, int B)
{


    int n = A.size();

    int low = 0 , high = n- 1;

    int r ;

    int mid = (low + high )/2;

    while (low<high)
    {
        if (A[mid][A[mid].size() - 1]<B)
        {
            low = mid +1;
            mid = (low + high )/2;
            // continue;


        }

        if (A[mid][A[mid].size() - 1]>B)
        {

            high = mid;

            if (A[low][A[low].size() - 1]<B)
            {
                low++;
            }
            
            mid = (low + high )/2;
            // continue;

                
        }

        if (A[mid][A[mid].size() - 1]==B)
        {

            return 1 ;

                
        }

        cout<<low<<" "<<mid<<" "<<high<<endl;


        if (low==mid&&high == mid)
        {
           r = mid;
            break; 
        }
        
        
        
    }


    // cout<<r<<endl;



    // return binary_search(A[r].begin(),A[r].end(),B);

    // return 0 ;
    
    



}

int main()
{

    vector<vector<int>> v = {  {5, 6, 6, 10, 11, 12, 12, 12, 15, 16},
                                {18, 18, 19, 21, 21, 21, 22, 22, 23, 24},
                                {29, 32, 32, 32, 33, 34, 34, 34, 35, 40},
                                {40, 42, 42, 43, 44, 46, 46, 47, 47, 47},
                                {48, 48, 48, 50, 51, 51, 51, 51, 51, 52},
                                {53, 56, 57, 59, 59, 60, 61, 61, 61, 63},
                                {63, 64, 64, 65, 65, 65, 67, 67, 67, 67},
                                {70, 73, 74, 74, 74, 75, 75, 79, 79, 81},
                                {82, 83, 83, 84, 84, 85, 86, 88, 89, 91},
                                {91, 91, 95, 95, 96, 96, 97, 99, 100, 100} };


    int b = 51;


    cout<<searchMatrix(v,b);



    return 0;
}