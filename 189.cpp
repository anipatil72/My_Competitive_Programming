#include <bits/stdc++.h>
using namespace std;

string removeSpecialCharacter(string s)
{
    for (int i = 0; i < s.size(); i++)
    {

        // Finding the character whose
        // ASCII value fall under this
        // range
        if (!isalnum(s[i]))
        {
            // erase function to erase
            // the character
            s.erase(i, 1);
            i--;
        }
    }

    return s;
}

int isPalindrome(string A)
{

    string s = removeSpecialCharacter(A);

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    //cout<<s<<endl;

    int n = s.length();

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{

    
    
    cout<<isPalindrome("1a2");

    return 0;
}