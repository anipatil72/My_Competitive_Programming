#include <bits/stdc++.h>
using namespace std;

bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;

    return false;
}

string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++)
    {
        // Do school mathematics, compute difference of
        // current digits

        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);

        // If subtraction is less than zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++)
    {
        int sub = ((str1[i] - '0') - carry);

        // if the sub value is -ve, then make it positive
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

int power(string a)
{
    int j = a.size();
    if (j == 1 && a[0] == '1')
    {
        return 0;
    }
    int f[j];
    for (int i = 0; i < j; i++)
    {
        f[i] = a[i] - '0'; // cout << f[i]<<":";
    }
    int k7 = 100;
    while (k7--)
    {
        for (int i = 0; i < j - 1; i++)
        {
            int k = f[i] % 2;
            int k1 = f[i] / 2;
            f[i + 1] = 10 * k + f[i + 1];
            f[i] = k1;
        }
        if (f[j - 1] % 2 == 0)
        {
            f[j - 1] = f[j - 1] / 2;
            /*for(int i=0;i<j;i++){cout<<f[i]<<" ";}
            cout << "\n";*/
            if (f[j - 1] == 1)
            {
                goto la;
            }
        }
        else if (f[j - 1] == 3 || f[j - 1] == 5 || f[j - 1] == 7 || f[j - 1] == 11 || f[j - 1] == 13 || f[j - 1] == 15 || f[j - 1] == 17 || f[j - 1] == 19 || f[j - 1] == 9)
        {
            return 0;
        }
        else if (f[j - 1] == 1)
        {
            goto la;
        }
        else
        {
            continue;
        }
    }



la:
    int flag = 0, flag1 = 0;



    if (f[j - 1] == 1)
    {
        for (int i = 0; i < j - 1; i++)
        {
            if (f[i] != 0)
            {
                flag = 1;
            }
        }
    }
    if (flag == 1)
    {
        return 0;
    }
    
        return 1;
    
}

int main()
{

    return 0;
}