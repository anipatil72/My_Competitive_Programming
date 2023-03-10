#include <bits/stdc++.h>
using namespace std;

int numMatchingSubseq(string s, vector<string> &words)
{

    int n = words.size();
    int l = s.length();

    int count = 0 ;

    for (int i = 0; i < n; i++)
    {
            int j = 0 , k = 0 ;
            while (j<l&&k<words[i].length())
            {
                if (s[j]==words[i][k])
                {
                    k++;
                    j++;
                    continue;

                }

                j++;
                
                
                
            }

                if (k==words[i].length())
                {
                     count++;   
                }
    }


    return count;
    
}

int main()
{

    string s = "abcde";
    vector<string> v =   {"acd"};

    cout<<numMatchingSubseq(s,v);

    return 0;
}