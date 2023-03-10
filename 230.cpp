#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &A) {

    int n = A.size();


    if (n==1)
    {
            return A[0];
    }
    

    string a = A[0];
    string b = A[1];

    int d = min(a.size(),b.size());





    string ans = "";

    // int  i = 0 , j = 0 ;

    // while (i<a.size()&&j<b.size())
    // {
    //     if (a[i]!=b[i])
    //     {
    //         break;
    //     }


    //     ans+= a[i];


    //     i++;
    //     j++;
        
    // }


    a = a.substr(0,d);
    b = b.substr(0,d);


    while (a!=b)
    {
        d--;

        a = a.substr(0,d);
        b = b.substr(0,d);
    }

    ans = a ;
    

    int k = ans.size();









    for (int i = 2; i < n; i++)
    {

        string temp = A[i].substr(0,k);

        while (temp!=ans)
        {

            k--;
            ans = ans.substr(0,k);
            temp = temp.substr(0,k);
        }
        


            
    }


    return ans ;
    
}

int main() 
{

   vector<string> v = {"abcdefgh","abcjk","abcghj","a"};

   cout<<longestCommonPrefix(v);

    

return 0;
}