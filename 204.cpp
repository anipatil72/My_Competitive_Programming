#include <bits/stdc++.h>
using namespace std;

string solve(string A, int B)
{

    int i = 0; // this is a pointer to check the char
    while (i < A.size())
    {
        int j = i;     // pointer which traverse forward
        int count = 0; // to count how many times its repeating
        for (j; j < A.size(); j++)
        {
            if (A[i] == A[j])
            {
                count++;
            } // counting repeating frequency
            else
            {
                break;
            }
        }
        if (count == B)
        {                      // checking if it has same frequency as given constraint
            A.erase(i, count); // removing if they match
        }
        else
        {
            i++;
        } // if not check for other elements of string
    }
    return A;
}

int main()
{

    cout << solve("aabbccddd", 2);

    return 0;
}