#include <bits/stdc++.h>
using namespace std;

bool canWinNim(int n)
{

    if (n<=3)
    {
            return true;
    }

    return !(n%4==0);
    
}

int main()
{

    return 0;
}