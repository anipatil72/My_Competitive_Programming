#include <bits/stdc++.h>
using namespace std;

int minPartitions(string n) {

    int s = n.length();

    char c = n[0];

    for (int i = 1; i < s; i++)
    {
           if (c < n[i])
           {
              c = n[i];  
           }
            
    }

    return (c - '0');
    

    
        
}

int main() 
{

    string s = "27346209830709182346";

    cout<<minPartitions(s);

return 0;
}