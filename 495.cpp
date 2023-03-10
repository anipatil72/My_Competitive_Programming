#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &A)
{

    int i = 0, j = 0;

    int n = A.size();

    int count = 0;

    int cand = A[i];

    while (i<n&&j<n)
    {

        while (j<n&&A[i]==A[j])
        {
            count++;
            j++;

            // cand = A[j];
        }

        if (count>=2)
        {
            A[i]=cand;
            A[++i] = cand;

            i++;

            count=1;
        }

        cand = A[j];
        
        
        
        
    }
    

    

}

int main()
{

    vector<int> a = {1,1,1,2,2,3};

    int n = removeDuplicates(a);

    for (int i = 0; i < n; i++)
    {
            cout<<a[i]<<" ";
    }
    

    return 0;
}