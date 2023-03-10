#include <bits/stdc++.h>
using namespace std;

string addBinary(string A, string B) {

    string ans = "";


    int n = A.length();
    int m = B.length();

    int carry = 0 ;

    int i = n-1 ,j =m-1 ;

    while (i>=0&&j>=0)
    {
        int cur = A[i] -'0' + B[j] -'0'+ carry;

        if (cur==2)
        {
            ans+= "0";  
            carry = 0;  
            continue;
        }

        else if (cur==3)
        {

            ans+="1";
            carry = 1;
            continue;
                
        }

        
        
        
    }
    







}

int main() 
{

return 0;
}