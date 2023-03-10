#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b)
{
    // int n = max(a.length(),b.length());
    int carry = 0;

    if (a.length() > b.length())
    {
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 && j >= 0)
        {

            if (a[i] == '1' && b[j] == '1' && carry == 0)
            {
                a[i] = '0';
                carry = 1;
            }
            else if ((a[i] == '1' && b[j] == '1') && (carry == 1))
            {
                a[i] = '1';
                carry = 1;
            }
            else if ((a[i] == '1' || b[j] == '1') && (carry == 0))
            {
                a[i] = '1';
                carry = 0;
            }
            else if ((a[i] == '1' || b[j] == '1') && (carry == 1))
            {
                a[i] = '0';
                carry = 1;
            }
            else if ((a[i] == '0' && b[j] == '0') && (carry == 0))
            {
                a[i] = '0';
                carry = 0;
            }
            else
            {
                a[i] = '1';
                carry = 0;
            }

            i--;
            j--;
        }

        
        
    }
}

int main()
{

    return 0;
}