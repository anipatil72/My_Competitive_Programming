// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

bool isAlienSorted(vector<string> &words, string order)
{

    unordered_map<char, int> m;

    for (int i = 0; i < 26; i++)
    {
        m[order[i]] = i;
    }

    for (int i = 0; i < words.size() - 1; i++)
    {
        string fir = words[i];

        string sec = words[i + 1];

        int mino = min(fir.length(), sec.length());

        bool flag = true;

        for (int j = 0; j < mino; j++)
        {

            if (fir[j] != sec[j])
            {
                if (m[fir[j]] < m[sec[j]])
                {

                    flag = false;
                    break;
                }
                else
                {

                    return false;
                }
            }
        }

        if (flag && fir.length() > sec.length())
        {
            return false;
        }
    }

    return true;
}

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{
    int n;
}

int main()
{

    string s = "aaaaabc";

    string c = "aaa";

    cout << (c < s) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥