#include <bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string s, vector<string> &words)
{

    int a = s.length();

    vector<int> ans;

    int n = words.size();

    int len = 0;

    for (int i = 0; i < n; i++)
    {
        len += words[i].length();
    }

    string temp;

    for (int i = 0; i < a - len + 1; i++)
    {
        temp = s.substr(i, len);

        // if (i == 8)
        // {

        //     cout << temp << endl;
        // }

        bool flag = true;

        unordered_map<string, int> m;

        for (int j = 0; j < n; j++)
        {

            // int p = (m.count(words[j])>0)?m[words[j]]:0;

            

            if (temp.find(words[j]) == string::npos)
            {
                // cout<<"Not Found !! "<<endl;

                flag = false;
                break;
            }
            else
            {
                int pos = temp.find(words[j]);


                for (int k = pos; k < pos + words[j].length(); k++)
                {
                    temp[k] = '0';
                }


                if (i == 1)
                {
                    cout << pos << endl;
                }


                if (i == 1)
                {
                    cout << temp << endl;
                }
            }
        }


        if (flag)
        {
            ans.push_back(i);
        }
    }

    return ans;
}

int main()
{

    string s = "ababaab";

    vector<string> v = {"ab","ba","ba"};

    //     "wordgoodgoodgoodbestword"
    //     ["word","good","best","word"]

            // "ababaab"
            // ["ab","ba","ba"]

    vector<int> ans = findSubstring(s, v);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}