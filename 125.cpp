#include <bits/stdc++.h>
using namespace std;

bool hotel(vector<int> &arrive, vector<int> &depart, int K)
{

    int count = 0;

    priority_queue<int,vector<int>,greater<int>> q ;

    q.push(depart[0]);

    

    for (int i = 1; i < arrive.size(); i++)
    {
        if (arrive[i] <= q.top())
        {

            q.push(depart[i]);
            count++;
        }

        if (arrive[i]>q.top())
        {
                while (arrive[i]>q.top())
                {
                    q.pop();
                }
                
        }
        
    }

    return K >= count;
}

int main()
{

    return 0;
}