#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string a, string b, string c)
{

    int n = a.size();

    int m = b.size();

    int k = c.size();

    if (m + n != k)
    {
        return false;
    }

    int i = 0, j = 0, l = 0;

    while (i < n || j < m)
    {
        if (a[i] == c[l] &&i < n)
        {
        // cout<<"I am here "<<c[l]<<endl;
            i++;
            l++;
            continue;
        }

        if (b[j] == c[l] &&j < m)
        {

        // cout<<"I am here "<<c[l]<<endl;
            j++;
            l++;
            continue;
        }



        // cout<<"I am here at breaking "<<c[l]<<endl;
        // cout<<i<<" "<<a[i]<<j<<" "<<b[j]<<endl;
        return false;
    }
    

    
    return true;


}

int main()
{

    string  s1 = "", s2 = "", s3 = "";


    cout<<isInterleave(s1,s2,s3);

    return 0;
}