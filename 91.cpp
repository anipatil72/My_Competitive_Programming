#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x)
{

    string s1 = to_string(x);
    string s2 = to_string(x);

    s1.assign(s1.begin(), s1.begin() + s1.size() / 2);

    cout<<s1<<endl;

    bool p;

    string s3 = s2.substr(s2.size() / 2 + s2.size()%2);

    cout<<s3<<endl;

    return s1 == s3;
}

int main()
{

    cout<<isPalindrome(2121)<<endl;

    return 0;
}