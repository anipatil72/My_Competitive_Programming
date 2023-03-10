#include <bits/stdc++.h>
using namespace std;

bool recur(vector<vector<char>> &board, string word, int i, int j, int cur, map<pair<int, int>, int> &map)
{
    int m = board.size();

    int n = board[0].size();

    if (cur + 1 > word.length())
    {
        return true;
    }

    bool a = false, b = false, c = false, d = false;

    if (i + 1 < m)
    {
        if (board[i + 1][j] == word[cur] && map[{i + 1, j}] == 0)
        {
            map[{i + 1, j}]++;
            a = recur(board, word, i + 1, j, cur + 1, map);
            map[{i + 1, j}]--;
        }
    }

    if (i - 1 >= 0)
    {
        if (board[i - 1][j] == word[cur] && map[{i - 1, j}] == 0)
        {
            map[{i - 1, j}]++;
            b = recur(board, word, i - 1, j, cur + 1, map);
            map[{i - 1, j}]--;
        }
    }

    if (j - 1 >= 0)
    {
        if (board[i][j - 1] == word[cur] && map[{i, j - 1}] == 0)
        {
            map[{i, j - 1}]++;
            c = recur(board, word, i, j - 1, cur + 1, map);
            map[{i, j - 1}]--;
        }
    }

    if (j + 1 < n)
    {
        if (board[i][j + 1] == word[cur] && map[{i, j+1}] == 0)
        {
            map[{i, j + 1}]++;
            d = recur(board, word, i, j + 1, cur + 1, map);
            map[{i, j + 1}]--;
        }
    }

    return a || b || c || d;
}

bool exist(vector<vector<char>> &board, string word)
{

    int m = board.size();

    int n = board[0].size();

    int l = word.length();

    map<pair<int, int>, int> map;

    bool check;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == word[0])
            {

                // pair<int,int> p = {i,j};

                map[{i, j}]++;

                check = recur(board, word, i, j, 1, map);

                map[{i,j}]--;

                if (check)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{

    vector<vector<char>> b = {{'a','a'}};
    string s = "aaa";

    cout<<exist(b,s);

    return 0;
}