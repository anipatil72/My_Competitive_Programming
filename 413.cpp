#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{

    unordered_map<char, int> m;

    for (int i = 0; i < 9; i++)
    {

        for (int j = 0; j < 9; j++)
        {
                
            if (board[i][j] != '.' && m.count(board[i][j]) > 0)
            {
                return 0;
            }

            if (board[i][j] != '.')
            {
                m[board[i][j]]++;
            }
        }
        
         m.clear();
    }



    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
                
            if (board[j][i] != '.' && m.count(board[j][i]) > 0)
            {
                return 0;
            }

            if (board[j][i] != '.')
            {
                m[board[j][i]]++;
            }
        }
        
         m.clear();
    }

  

    for (int i = 0; i < 9; i++)
    {
        

            for (int j = 0; j < 9; j++)
            {
                    
                if (board[((i/3)*3 + j /3)][((3*i)%9 + j%3)] != '.' && m.count(board[((i/3)*3 + j /3)][((3*i)%9 + j%3)]) > 0)
                {
                    return 0;
                }

                if (board[((i/3)*3 + j /3)][((3*i)%9 + j%3)] != '.')
                {
                    m[board[((i/3)*3 + j /3)][((3*i)%9 + j%3)]]++;
                }
            }
        
         m.clear();
                
        
        
    }

    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //     {
    //             cout<<board[((3*i)%9 + j /3)][((3*i)%9 + j%3)]<< " ";
    //     }

    //     cout<<endl;
        
    // }
    
    
    return true;
    
}

int main()
{

    return 0;
}