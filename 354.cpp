#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int colorful(int A)
{
    vector<int> digits;
    unordered_set<int> st;

    while (A != 0)
    {
        digits.push_back(A % 10);
        A /= 10;
    }

    int N = digits.size();
    // reverse(digits.begin(), digits.end());

    int x = 0;
    vector<int> v(N, 1);

    for (int i = 0; i < N; i++)
    {

        long long prod = 1;
            for (int j = i; j < N; j++)
            {
                prod = prod*digits[j]; 
                auto itr = st.find(prod);
                if (itr != st.end())
                {
                    return 0;
                }
                st.insert(prod);   
            }
            
    }
    

    return 1;
}

int main()
{

    return 0;
}