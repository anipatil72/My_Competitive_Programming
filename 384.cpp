#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    int n = s.length();

    if (n%2==1)
    {
            return false;
    }

    stack<char> d ;

    for (int i = 0; i < n; i++)
    {
            if (s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                  d.push(s[i]);  
            }

            if (s[i]==')')
            {
               if (!d.empty())
               {
                    if (d.top()=='(')
                    {
                            d.pop();
                    }
                    else
                    {
                        return false;
                    }
                    
                    
               }
               else
               {
                   return false;
               }

                    
            }
            if (s[i]=='}')
            {
               if (!d.empty())
               {
                    if (d.top()=='{')
                    {
                            d.pop();
                    }
                    else
                    {
                        return false;
                    }
                    
                    
               }
               else
               {
                   return false;
               }

                    
            }
            if (s[i]==']')
            {
               if (!d.empty())
               {
                    if (d.top()=='[')
                    {
                            d.pop();
                    }
                    else
                    {
                        return false;
                    }
                    
                    
               }
               else
               {
                   return false;
               }

                    
            }
            
            
    }

    if (!d.empty())
    {
       return false;     
    }
    
    
    return true;
}

int main()
{

    return 0;
}