#include <bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k)
{

    string temp = "";

    for (int i = 0; i < n; i++)
    {

        temp += to_string(i + 1);
    }

    for (int i = 1; i < k; i++)
    {
            next_permutation(temp.begin(),temp.end());
    }


    return temp;
    
}

int main()
{


    string s = "1234";

    cout<<s<<endl;

    for (int i = 1; i < 24; i++)
    {

        next_permutation(s.begin(),s.end());
        cout<<s<<endl;
            // cout<<getPermutation(s);
    }
    


    // next_permutation(s.begin(),s.end());

    // cout<<s<<endl;

    return 0;
}