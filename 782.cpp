// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

// returns set of all divisors of a natural number                    

vector<int> getDivisors(int n)
{

   set<int> s;

    // Note that this loop runs till square root
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
           // If divisors are equal, print only one
           if (n / i == i)
           {

              s.insert(i);
           }
           else
           { // Otherwise print both

              s.insert(i);
              s.insert(n / i);
           }
     }
 }

    vector<int> ans(s.begin(), s.end());

 return ans;
}


bool isThree(int n)
{
    vector<int> s = getDivisors(n);

    return s.size()==3;
    
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥