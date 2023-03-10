#include <bits/stdc++.h>
using namespace std;

string solve(string A) {

    int n = A.length();

    string s = "";

    unordered_map<char,int> m ;

    for (int i = 0; i < n; i++)
    {
        m[A[i]]++;
    }

    for (int i = 0; i < n; i++)
    {

        //cout<<m[A[i]]<<endl;

        if (m[A[i]]!=-1)
        {
            s = s + A[i] + to_string(m[A[i]]);

            m[A[i]] = -1;
                
        }
        
    }
    
    return s ;
}

int main() 
{


    string s = "a";


    cout<<solve(s);

return 0;
}