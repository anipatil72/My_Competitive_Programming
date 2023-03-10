#include <bits/stdc++.h>
using namespace std;

vector<string> fizzBuzz(int A)
{

    vector<string> v;

    for (int i = 1; i <= A; i++)
    {
        if (i%3==0&&i%5!=0)
        {
                v.push_back("Fizz");
                
        }
        else if (i%5==0&&i%3!=0)
        {
                v.push_back("Buzz");
                
        }
        else if (i%3==0&&i%5==0)
        {
                v.push_back("FizzBuzz");
        }
        else
        {
            v.push_back(to_string(i));
            
        }
        
        
        
        
        
        
        
          
    }

    return v;
    
}

int main()
{

    return 0;
}