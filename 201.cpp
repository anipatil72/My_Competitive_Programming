#include <bits/stdc++.h>
using namespace std;

// A function to perform division of large numbers
string longDivision(string number, int divisor)
{
    // As result can be very large store it in string
    string ans;
 
    // Find prefix of number that is larger
    // than divisor.
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');
 
    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while (number.size() > idx) {
        // Store result in answer i.e. temp / divisor
        ans += (temp / divisor) + '0';
 
        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
 
    // If divisor is greater than number
    if (ans.length() == 0)
        return "0";
 
    // else return ans
    return ans;
}

int power(string A) 
{

    int n = A.length();

    int ld = A[n-1] - '0';

    if (ld%2==1)
    {
            return 0 ;
    }
    
    

    string s = longDivision(A,2);
        // cout<<s<<endl;

    while (s.length()>2)
    {

        int n = s[s.length() - 1] - '0';

        if (n%2==1||n==0)
        {
            return 0 ;

        }

        s = longDivision(s,2);

        


    }


    int last = stoll(s);

    //cout<<last<<endl;

    if ((last&(last-1))==0)
    {

        return 1 ;
    }
    
    

        //cout<<"I am here!"<<endl;

    
    return 0 ;

}




int main() 
{


    cout<<power("18446744073709551616");

    //cout<<(128&127)<<endl;

    

return 0;
}