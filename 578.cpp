#include <bits/stdc++.h>
using namespace std;

char nextGreatestLetter(vector<char> &letters, char target)
{
    int n = letters.size();

    auto itr = upper_bound(letters.begin(), letters.end(), target);

    if (itr == letters.end())
    {
        return letters[0];
    }

    return *itr;
}

int main()
{

    vector<char> v = {'a', 'c', 'f', 'i', 'q', 'r', 'v'};

    cout<<nextGreatestLetter(v,'z');

    return 0;
}