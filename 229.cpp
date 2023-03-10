#include <bits/stdc++.h>
using namespace std;

string solve(string A) {

    int n = A.length();

    for (int i = 0; i < n; i++)
    {
            if (A[i]>='a'&&A[i]<='z')
            {
                    A[i] -= 32 ;
                    continue;
            }


            A[i]+= 32;
            
    }
    

    




    return A;

}

int main() 
{

    string s = "Aniruddha";

    cout<<solve(s);

    

return 0;
}