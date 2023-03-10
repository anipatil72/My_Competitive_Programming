#include <bits/stdc++.h>
using namespace std;

int reverse(int A)
{

    if (A > INT_MAX)
    {
        return 0;
    }

    if (A > 0)
    {
        string s = to_string(A);

        int n = s.length();

        for (int i = 0; i < n / 2; i++)
        {
            swap(s[i],s[n - i - 1]);
        }

        while (s[0] == '0')
        {
            s.erase(s.begin());
        }

        if (stoll(s)> INT_MAX)
        {
              return 0 ;  
        }
        

        return stoll(s) ;
    }

    string b = to_string(A);

    b = b.substr(1);

    //cout<<b<<endl;

    int n1 = b.length();

    for (int i = 0; i < n1 / 2; i++)
    {
        swap(b[i], b[n1 - i - 1]);
    }

    while (b[0] == '0')
    {
        b.erase(b.begin());
    }

    if (stoll(b)> INT_MAX)
        {
              return 0 ;  
        }

    return (-1) * stoll(b);
}

int main()
{

    long a = -1234567891 ;

    //cout<<reverse(a);

    



    return 0;
}