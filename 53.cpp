#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{

    stack<char> a;

    string s;
    bool ans;

    char c, j, k;

    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            a.push(s[i]);
        }

        if (s[i] == ')' && a.top() == '(')
        {
            a.pop();
        }

        if (s[i] == ']' && a.top() == '[')
        {
            a.pop();
        }

        if (s[i] == '}' && a.top() == '{')
        {
            a.pop();
        }

        if (s[i] == '}' || s[i] == ']' || s[i] == ')')
        {
            ans = false;
        }
    }

    ans = a.empty();

    cout << ans << endl;

    return 0;
}