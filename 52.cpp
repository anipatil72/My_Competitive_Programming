#include <bits/stdc++.h>
using namespace std;

int main() 
{

    stack <char> s ;

    s.push('c');
    s.push('h');
    s.push('t');
    s.push('!');
    s.push('p');

    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;

return 0;
}