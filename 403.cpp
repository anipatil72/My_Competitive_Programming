#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B, vector<int> &C)
{

    map<int,pair<int,int>> m;
    vector<int> ans;


    int counter = 0 ;

    for (int i = 0; i < A.size(); i++)
    {

        if ((m.count(A[i])>0)&&(m[A[i]].first<A.size()))
        {
                counter++;
                continue;
        }
        
        
        

            m[A[i]].first = counter;
            m[A[i]].second++;
            counter++;
    }


    for (int i = 0; i < B.size(); i++)
    {

        if ((m.count(B[i])>0)&&(m[B[i]].first<A.size() + B.size())&&(m[B[i]].first >=A.size()))
        {
                counter++;
                continue;
        }
        
        
        

            m[B[i]].first = counter;
            m[B[i]].second++;
            counter++;
    }


    for (int i = 0; i < C.size(); i++)
    {

        if ((m.count(C[i])>0)&&(m[C[i]].first<A.size() + B.size() + C.size())&&(m[C[i]].first >=A.size() + B.size()))
        {
                counter++;
                continue;
        }
        
        
        

            m[C[i]].first = counter;
            m[C[i]].second++;
            counter++;
    }
    




    for (auto it = m.begin(); it!=m.end() ; it++)
    {
         if (((it->second).second)>=2)
         {
            ans.push_back(it->first);    
         }
         
         
            
    }

    return ans;
    
    
}

int main()
{

    return 0;
}