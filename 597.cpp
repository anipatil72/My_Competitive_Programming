#include <bits/stdc++.h>
using namespace std;

int recur(string start, string end, unordered_map<string, int> &m, int ans, int tick)
{

    if (tick>=100)
    {
            return INT_MAX;
    }
    

    if (start == end)
    {
        return ans;
    }

        int a, b , c, d;


    for (int i = 0; i < 8; i++)
    {
        char d = start[i];


        start[i] = 'A';

        if (m[start] != 0&&d!='A')
        {
             a = recur(start, end, m, ans + 1, tick + 1);
        }

        start[i] = 'T';

        if (m[start] != 0&&d!='T')
        {
             b = recur(start, end, m, ans + 1, tick + 1);
        }

        start[i] = 'G';

        if (m[start] != 0&&d!='G')
        {
             c = recur(start, end, m, ans + 1, tick + 1);
        }

        start[i] = 'C';

        if (m[start] != 0&&d!='C')
        {
             d = recur(start, end, m, ans + 1, tick + 1);
        }

        start[i] = d;
    
    }

    int x = min(min(a, b), min(c,d));

    if (x==INT_MAX)
    {
        return -1;    
    }

    return x;
    


    
}

int minMutation(string start, string end, vector<string> &bank)
{

    int n = bank.size();

    unordered_map<string, int> m;

    for (int i = 0; i < n; i++)
    {
        m[bank[i]]++;
    }

    int count = 0;

    int tick = 0 ;

    int ans = recur(start, end, m, count, tick);

    

    return count;
}

int main()
{

    string start = "AACCGGTT";
    string end = "AAACGGTA";
    vector<string> bank = {"AACCGATT", "AACCGATA", "AAACGATA", "AAACGGTA"};

    cout << minMutation(start, end, bank);

    return 0;
}

// "AACCGGTT"
// "AAACGGTA"
// ["AACCGATT","AACCGATA","AAACGATA","AAACGGTA"]