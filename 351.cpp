#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{

    int n = s.length();

    if (n==1)
    {
        return s;
    }

    if (n==2)
    {
        if (s[0]==s[1])
        {
                return s;
        }
        else
        {
            return s.substr(0,1);
        }
        
        
    }
    
    

    //for odd length 

    int M = 1;
    string ans = s.substr(0,1);

    for (int p = 1; p < n-1; p++)
    {
        int len = 1;

        int i = p , j =  i + 1 , k = i-1;

        while (k>=0&&j<n&&s[j]==s[k])
        {
            len+=2;

            if (len>M)
            {
                M = len;
                ans = s.substr(k,len);   
            }


            j++;
            k--;
            


        }
            
    }

    //for even length

    for (int p = 0; p < n-1; p++)
    {
        int len = 0;

        int i = p , j =  i + 1 , k = i;

        while (k>=0&&j<n&&s[j]==s[k])
        {
            len+=2;

            if (len>M)
            {
                M = len;
                ans = s.substr(k,len);   
            }


            j++;
            k--;
            


        }
            
    }


    
    return ans;
    
}

int main()
{

    string s = "ccd";

    cout<<longestPalindrome(s);

    return 0;
}