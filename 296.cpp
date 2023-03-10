#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &A, int B)
{

    int n = A.size();

    int i = 0 , j = 0 ;

    while (i<n&&j<n)
    {
        if (A[j]==B)
        {
            j++;
            continue;
        }

        A[i] = A[j];
        i++;
        j++;

        
    }


    return i;

    
}

int main()
{


    vector<int> v = {1,2,3,4,5,6,6,7,8,9,0,4,3,6,6,1,1,1,1,1,4,5};

    int a = removeElement(v,6);

    for (int i = 0; i < a; i++)
    {
            cout<<v[i]<<" ";
    }
    

    return 0;
}