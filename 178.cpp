#include <bits/stdc++.h>
using namespace std;

// bool myComp(vector<int> &a, vector<int> &b)
// {

//     if (a[0] == b[0])
//     {
//         return a[1] < b[1];
//     }

//     return a[0] > b[0];
// }

// vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
// {

//     int n = people.size();

//     vector<vector<int>> ans;

//     sort(people.begin(), people.end(), myComp);

//     for (int i = 0; i < n; i++)
//     {

//         if (people[i][1] != i)
//         {
//             vector<int> man = people[i];

//             int cori = man[1];

//             people.erase(people.begin() + i, people.begin() + i + 1);

//             people.insert(people.begin() + cori, man);
//         }
//     }

//     return people ;
// }

class Solution {
public:
    
bool myComp(vector<int> &a, vector<int> &b)
{

    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }

    return a[0] > b[0];
}


vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
{

    int n = people.size();

    vector<vector<int>> ans;

    sort(people.begin(), people.end(), myComp);

    for (int i = 0; i < n; i++)
    {

        if (people[i][1] != i)
        {
            vector<int> man = people[i];

            int cori = man[1];

            people.erase(people.begin() + i, people.begin() + i + 1);

            people.insert(people.begin() + cori, man);
        }
    }

    return people ;
}
};

int main()
{

    Solution s;

    vector<vector<int>> v = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};

    vector<vector<int>> a = s.reconstructQueue(v);

    for (int i = 0; i < a.size() ; i++)
    {
         for (int j = 0; j < 2; j++)
         {
                cout<<a[i][j]<<" ";
         }

         cout<<endl;
            
    }
    

    

    return 0;
}