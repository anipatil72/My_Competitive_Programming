#include <bits/stdc++.h>
using namespace std;

int leftRepChar(string s)
{
   const int CHAR = 256 ;

   int n = s.length();

   int count[CHAR] = {0};

   for (int i = 0; i < n; i++)
   {
        count[s[i]]++;

   }


   for (int i = 0; i < n; i++)
   {
        if (count[s[i]]>=2)
        {
             return i ;   
        }
        
   }
   
   
    return -1 ;

}

int main() 
{

    string s1 = "geeksforgeeks";
    string s2 = "abbcc";
    string s3 = "abccb";

    string s4 = "abcd";

    cout<<leftRepChar(s4)<<endl;

return 0;
}