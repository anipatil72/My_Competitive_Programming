#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s)
{

    int n = s.length();

    int i = n-1;


    while (s[i]==' '&&i>0)
    {
        i--;
    }


    // string word = "";
    int count = 0 ;

    while (s[i]!=' '&&i>=0)
    {
        count++;
        i--;
    }

    // reverse(word.begin(),word.end());

    return count;   

}

int main()
{

    string s = "a";

    cout<<lengthOfLastWord(s);

    return 0;
}