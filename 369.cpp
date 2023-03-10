#include <bits/stdc++.h>
using namespace std;

vector<string> letterCombinations(string digits)
{
    int n = digits.length();

    if (n == 0)
    {
        return {};
    }

    vector<vector<char>> v(8);

    char c = 'a';

    for (int i = 0; i < 8; i++)
    {
        v[i].push_back(c);
        // cout<<c<<" ";
        c++;
        v[i].push_back(c);
        // cout<<c<<" ";
        c++;
        v[i].push_back(c);
        // cout<<c<<" ";
        c++;

        if (i == 5 || i == 7)
        {

            v[i].push_back(c);
            // cout<<c<<" ";
            c++;
        }

        // cout<<"\n";
    }

    vector<string> ans;

    string temp = "";

    if (n == 1)
    {
        for (int i = 0; i < v[digits[0] - '2'].size(); i++)
        {
            temp += v[digits[0] - '2'][i];

            ans.push_back(temp);

            temp.pop_back();
        }
    }

    if (n == 2)
    {
        for (int i = 0; i < v[digits[0] - '2'].size(); i++)
        {
            temp += v[digits[0] - '2'][i];

            for (int j = 0; j < v[digits[1] - '2'].size(); j++)
            {
                temp += v[digits[1] - '2'][j];
                ans.push_back(temp);

                temp.pop_back();
            }

            temp.pop_back();
        }
    }

    if (n == 3)
    {

        for (int i = 0; i < v[digits[0] - '2'].size(); i++)
        {
            temp += v[digits[0] - '2'][i];

            for (int j = 0; j < v[digits[1] - '2'].size(); j++)
            {
                temp += v[digits[1] - '2'][j];

                for (int k = 0; k < v[digits[2] - '2'].size(); k++)
                {
                    temp += v[digits[2] - '2'][k];
                    ans.push_back(temp);

                    temp.pop_back();
                }

                temp.pop_back();
            }

            temp.pop_back();
        }
    }

    if (n == 4)
    {
        for (int i = 0; i < v[digits[0] - '2'].size(); i++)
        {
            temp += v[digits[0] - '2'][i];

            for (int j = 0; j < v[digits[1] - '2'].size(); j++)
            {
                temp += v[digits[1] - '2'][j];

                for (int k = 0; k < v[digits[2] - '2'].size(); k++)
                {
                    temp += v[digits[2] - '2'][k];
                    for (int l = 0; l < v[digits[3] - '2'].size(); l++)
                    {
                        temp += v[digits[3] - '2'][l];
                        ans.push_back(temp);

                        temp.pop_back();
                    }

                    temp.pop_back();
                }

                temp.pop_back();
            }

            temp.pop_back();
        }
    }

    return ans;
}

int main()
{
    vector<string> ans = letterCombinations("23");

    for (int i = 0; i < ans.size(); i++)
    {
            cout<<ans[i]<<" ";
    }
    

    return 0;
}