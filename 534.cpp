#include <bits/stdc++.h>
using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t ans = 0;

    for (int i = 0; i < 31; i++)
    {
        int t = (n&(1<<i));

        if (t)
        {
                int d = 31 - i;

                int k = (1<<d);

                ans = (ans|k);
        }
        
    }

    return ans;
    
}

int main()
{
    int n = 1;

    int a = 1<<1;

    // n<<2;

    cout<<n;

    return 0;
}