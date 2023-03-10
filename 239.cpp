#include <bits/stdc++.h>
using namespace std;

int solve(string A)
{
    while (*(A.begin())==' ')
    {
        A.erase(A.begin());
    }
    


    while (A[A.length() - 1]==' ')
    {
        A.erase(A.end() - 1);
    }

    

    int n = A.length();


    if (n==0)
    {
            return 0 ;
    }
    


    int spacecount = 0 ;




    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] == ' ')
        {

            while (A[i] == ' ')
            {
                i++;
                spacecount++;
            }
            count++;
        }
    }

    count++;


    
    

    return count;
}

int main()
{

    string s = "      ";

    cout << solve(s);

    return 0;
}