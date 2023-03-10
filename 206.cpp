#include <bits/stdc++.h>
using namespace std;

vector<int> solve(string A) {

    int n = A.size();

    int count[26] = {0};

    for (int i = 0; i < n; i++)
    {
        count[A[i]-'a']++;
    }

    vector<int> v ;



    for (int i = 0; i < n; i++)
    {

        if (count[A[i] - 'a']>0)
        {
            v.push_back(count[A[i] - 'a']);

            count[A[i] - 'a'] = -1;
                
        }
        

        
    }
    
    
    return v ;
    
}

int main() 
{

    string s = "interviewbit";

    vector<int> a = solve(s);

    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    

return 0;
}