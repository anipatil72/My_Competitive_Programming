#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <errno.h>

using namespace std;

// class Solution
// {
// public:
string removeDigit(string number, char digit)
{

    string a;

    int i, j, k = 1, r;

    for (i = 0; i < number.length(); i++)
    {
        string s = number;
        // cout<<s<<endl;
        //  cout<<"The new string is "<<s[i]<<endl;
        //  cout<<"The character now is "<<s[i]<<endl;

        if (s[i] == digit)
        {
            s.erase(s.begin() + i);
            // cout<<s<<endl;

            if (k)
            {
                a = s;
                k = 0;
            }

            if (stoi(s) > stoi(a))
            {
                a = s;
            }
        }
    }

    return a;
}
// };

int main()
{
    string x = "51578165";
    string y = removeDigit(x, '1');

    cout << y;

    // x.erase(4,5);

    // cout<<x ;

    return 0;
}