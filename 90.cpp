#include <bits/stdc++.h>
using namespace std;

#define ll long long 

void rotate(vector<vector<int> > &A) {

    for (int i = 0; i < A.size(); i++)
    {
            for (int j = i; j < A[i].size(); j++)
            {
                swap(A[i][j],A[j][i]);
            }
            
    }

    for (int i = 0; i < (A.size())/2; i++)
    {
            for (int j = 0; j < A.size(); j++)
            {
                    swap(A[j][i],A[j][A.size()-1-i]);
            }
            
    }
    
    
    
}

int main()
{

    vector <vector<int>> v = {{1,2},{3,4}};

    //cout<<v.size()<<endl;
    //  for (int i = 0; i < v.size()/2; i++)
    // {
    //         swap(v[i],v[v.size()-1-i]);
    // }

    rotate(v);

    


    for (int i = 0; i < v.size(); i++)
    {

        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
                
        }

        cout<<endl;
        
    }

    return 0;
}