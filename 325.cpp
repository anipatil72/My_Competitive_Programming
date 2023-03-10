#include <bits/stdc++.h>
using namespace std;

vector<int> findOccurences(vector<int> &A)
{

    int n = A.size();

    map<int,int> m;

    for (int i = 0; i < n; i++)
    {
         m[A[i]]++;

    }


    vector<int>v(m.size(),0);

    int count = 0 ;

    for (auto i = m.begin(); i!= m.end(); i++)
    {

        v[count]= i->second;
        count++;
        
    }

    return v;
    
    
}

int main()
{

    return 0;
}