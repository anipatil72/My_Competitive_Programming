#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& v)
{
    int n = v.size();

    for (int i = 1; i < n; i++)
    {
        int j = i ;
            while (j>0&&v[j-1]>v[j])
            {
                swap(v[j-1],v[j]);
                j--;
            }
            
    }
    
}

int main() 
{


    vector<int> v = {4,1,6,3,0,-3,12,109,89,24,-100,765,435,134,1209};

    insertionSort(v);


    for (int i = 0; i < v.size(); i++)
    {
            cout<<v[i]<<" ";
    }
    

return 0;
}