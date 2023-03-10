#include <bits/stdc++.h>
using namespace std;

int convertStringToInt(string s)
{
    int num = 0;
  
    // convert binary string into integer
    for (int i = 0; i < s.size(); i++) {
        num = num * 2 + (s[i] - '0');
    }
    return num;
}
  

int solve(int n) {
    // base case
    if (n == 1)
        return 1;
    n--;
  
    // stores the binary palindrome string
    queue<string> q;
  
    // add 2nd binary palindrome string
    q.push("11");
  
    // runs till the nth binary palindrome number
    while (!q.empty()) {
        // remove curr binary palindrome string from queue
        string curr = q.front();
        q.pop();
        n--;
  
        // if n==0 then we find the n'th binary palindrome
        // so we return our answer
        if (!n) {
            return convertStringToInt(curr);
        }
  
        int mid = curr.size() / 2;
  
        // if length is even .so it is our first case
        // we have two choices
        if (curr.size() % 2 == 0) {
            string s0 = curr, s1 = curr;
            s0.insert(mid, "0");
            s1.insert(mid, "1");
            q.push(s0);
            q.push(s1);
        }
          
        // if length is odd .so it is our second case
        // we have only one choice
        else {
            string ch(1, curr[mid]);
            string temp = curr;
            temp.insert(mid, ch);
            q.push(temp);
        }
    }
  
    return 0;
}

int main()
{

    int a = 20000;

    cout << solve(a);

    return 0;
}