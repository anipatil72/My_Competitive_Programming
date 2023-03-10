#include <iostream>
using namespace std;

void printPer(char s[])
{

    
    if (s[0] == '\0')
    {
        return;
    }

    if (s[0]!= '\0')
    {
        printf("%c", s[0]);
        printPer(s+1);

        printPer(s+1);
        printf("%c", s[0]);
    }
}

int main()
{

    char str[10];
    int n;

    cin >> str;

  

    cout << n << endl;

    return 0;
}