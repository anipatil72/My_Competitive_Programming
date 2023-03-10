#include <bits/stdc++.h>
using namespace std;

string solve(string A)
{

    string final = "";

    int n = A.length();

    int i = n - 1;

    while (i >= 0)
    {
        if (A[i] != ' ')
        {
            break;
        }

        i--;
    }

    //cout<<i<<endl;

    string word = "";

    while (i >= 0)
    {
        if (A[i] != ' ')
        {
            word += A[i];

            //cout<<A[i]<<" ";
        }

        else if (A[i] == ' '&&A[i+1]!=' ')
        {
            reverse(word.begin(), word.end());

            //cout<<word<<endl;

            final =  final + word + ' ';

            word = "";
        }

        

        
        

        i--;
    }

            reverse(word.begin(),word.end());
            final+= word ;
    //cout<<i<<endl;

    while (final[final.length()-1]==' ')
    {
        final.erase(final.begin() + final.length() - 1);
    }
    

    return final;


}

int main()
{

    //string s = " hello  world   ";

    //cout<<solve(s)<<1;

    //cout<<1<<2<<endl;

    bool b = stoll("980765432198765")>INT_MAX;

    cout<<b<<endl;
    return 0;
}