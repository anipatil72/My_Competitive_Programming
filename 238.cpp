#include <bits/stdc++.h>
using namespace std;

int solve(string A)
{

    A.erase(A.begin() + 2);

    string s = A;

    int a = stoi(s);

    int d = a / 100;

    int e = d % 10;

    string p = A.substr(0, 2);

    p += A.substr(0, 2);

    reverse(p.begin() + 2, p.end());

    int v = stoi(p);

    if (d == 23&&a%100>32)
    {
        return 60 - a % 100;
    }

    if (e <= 5 && (v - a) >= 0)
    {

        return v - a;
    }

    if (e < 5 && (v - a) < 0)
    {
        string f = A.substr(0, 2);

        f[1]++;

       

        

        

        string h = f + f;

        reverse(h.begin()+2, h.end());


        //cout<<h<<endl;

        int z = stoi(h);

        return z % 100 + 60 - a % 100;
    }

    if (d < 10)
    {
        return (10 - d - 1) * 60 + 1 + 60 - a % 100;
    }

    if (d < 20)
    {
        return (20 - d - 1) * 60 + 2 + 60 - a % 100;
    }

    return -1;
}

int main()
{

    string t = "18:00";

    cout << solve(t);

    return 0;
}